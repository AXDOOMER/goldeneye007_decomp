#include <ultra64.h>
#include "bondtypes.h"
#include "limits.h"

// rodata

/*
* Address: 0x7f0b3200
*/
f32 calculateInterpolationFactor(coord2d *start1, coord2d *end1, coord2d *start2, coord2d *end2)
{
    f32 deltaX = start2->f[1] - end2->f[1];
    f32 deltaY = end2->f[0] - start2->f[0];
    f32 a = (start2->f[1] - start1->f[1]) * deltaY + (start2->f[0] - start1->f[0]) * deltaX;
    f32 b = (end1->f[1] - start1->f[1]) * deltaY + (end1->f[0] - start1->f[0]) * deltaX;

    if (b == 0.0f)
    {
        return 1.0f;
    }

    a /= b;

    if (a < 0.0f || a > 1.0f)
    {
        return 1.0f;
    }

    return a;
}


/*
* Address: 0x7F0B32D8
*/
f32 calculateGeometricLimit(struct coord3d *point3D, coord2d *lineStart, coord2d *lineEnd)
{
    f32 projection1;
    f32 projection2;
    f32 deltaSquared;
    f32 deltaX;
    f32 deltaY;

    deltaX = lineEnd->x - point3D->y;
    deltaY = lineEnd->y - point3D->z;

    projection2 = deltaY * lineStart->x - deltaX * lineStart->y;
    projection1 = deltaX * lineStart->x + deltaY * lineStart->y;

    deltaSquared = (point3D->x - projection2) * (point3D->x + projection2);

    if (deltaSquared < 0.0f)
    {
        return FLT_MAX;
    }

    projection1 -= sqrtf(deltaSquared);

    if (projection1 < 0.0f)
    {
        if (projection1 * projection1 + projection2 * projection2 <= point3D->x * point3D->x)
        {
            return 0.0f;
        }

        return FLT_MAX;
    }

    return projection1;
}


/*
* Address: 0x7f0b33dc
*/
f32 calculateNormalizedIntersection(coord3d *point3D, coord2d *lineStart, coord2d *lineEnd, coord2d *direction)
{
    f32 directionLength ;
    f32 tempCrossProduct;
    coord2d normalizedDir;
    f32 deltaY;
    f32 deltaX;
    f32 lineLength;
    f32 inverseLineLength ;
    f32 normalY;
    f32 normalX;
    f32 proj1;
    f32 proj2;
    f32 intersectionStartY;
    f32 intersectionStartX;
    f32 intersectionEndY;
    f32 intersectionEndX;
    f32 crossEnd;
    f32 crossStart;
    f32 crossEndLineEnd;
    f32 intersectionFactor;
    f32 intersectionFactorLineEnd;
    f32 projectedStartDiff;
    f32 projectedEndDiff;

    directionLength  = sqrtf(direction->x * direction->x + direction->y * direction->y);

    if (directionLength  == 0.0f)
    {
        return 1.0f;
    }

    normalizedDir.x = direction->x * (1.0f / directionLength );
    normalizedDir.y = direction->y * (1.0f / directionLength );

    deltaX = lineEnd->x - lineStart->x;
    deltaY = lineEnd->y - lineStart->y;

    lineLength = sqrtf(deltaX * deltaX + deltaY * deltaY);

    if (lineLength == 0.0f)
    {
        goto handlezero;
    }

    inverseLineLength  = 1.0f / lineLength;
    normalX = deltaY * inverseLineLength ;
    normalY = -deltaX * inverseLineLength ;

    proj1 = point3D->x * normalX;
    proj2 = point3D->x * normalY;

    if (proj1 * (point3D->y - lineStart->x) + proj2 * (point3D->z - lineStart->y) < 0.0f)
    {
        proj1 = -proj1;
        proj2 = -proj2;
    }

    intersectionStartX = lineStart->x + proj1;
    intersectionStartY = lineStart->y + proj2;
    intersectionEndX = lineEnd->x + proj1;
    intersectionEndY = lineEnd->y + proj2;

    crossStart = (direction->y * intersectionStartX) - (intersectionStartY * direction->x);
    crossEnd = (point3D->y * direction->y) - (point3D->z * direction->x);
    crossEndLineEnd = (direction->y * intersectionEndX) - (intersectionEndY * direction->x);

    if (crossEndLineEnd < crossStart)
    {
        coord2d *tmp;

        tempCrossProduct = crossStart;
        crossStart = crossEndLineEnd;
        crossEndLineEnd = tempCrossProduct;

        tmp = lineStart;
        lineStart = lineEnd;
        lineEnd = tmp;

        normalX = -normalX;
        normalY = -normalY;
    }

    if (crossEndLineEnd == crossStart)
    {
        intersectionFactor = calculateGeometricLimit(point3D, &normalizedDir, lineStart);
        intersectionFactorLineEnd = calculateGeometricLimit(point3D, &normalizedDir, lineEnd);

        if (intersectionFactorLineEnd < intersectionFactor)
        {
            intersectionFactor = intersectionFactorLineEnd;
        }
    }
    else if (crossEndLineEnd < crossEnd)
    {
handlezero:
        intersectionFactor = calculateGeometricLimit(point3D, &normalizedDir, lineEnd);
    }
    else if (crossEnd < crossStart)
    {
        intersectionFactor = calculateGeometricLimit(point3D, &normalizedDir, lineStart);
    }
    else
    {
        projectedStartDiff = normalX * (point3D->y - lineStart->x) + normalY * (point3D->z - lineStart->y);
        projectedEndDiff = normalX * (point3D->y + direction->x - lineStart->x) + normalY * (point3D->z + direction->y - lineStart->y);

        if (projectedStartDiff == projectedEndDiff)
        {
            return 1.0f;
        }

        intersectionFactor = (projectedStartDiff - point3D->x) * directionLength  / (projectedStartDiff - projectedEndDiff);
    }

    if (directionLength  < intersectionFactor)
    {
        return 1.0f;
    }

    if (intersectionFactor < 0.0f)
    {
        return 0.0f;
    }

    return (f32) intersectionFactor * (1.0f / directionLength );
}
