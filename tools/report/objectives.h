#define MISSIONS_A_MAX 18
#define MISSIONS_SA_MAX 19
#define MISSIONS_00A_MAX 20
#define MISSIONS_MAX (MISSIONS_A_MAX + MISSIONS_SA_MAX + MISSIONS_00A_MAX + 1)
#define OBJECTIVES_MAX (OBJ_MAX + 1)

enum OBJECTIVES
{
	OBJ_A = 0,
	OBJ_B,
	OBJ_C,
	OBJ_D,
	OBJ_E,
	OBJ_MAX
};

enum OBJECTIVE_LINES
{
	LINE1 = 0,
	LINE2
};

enum VERBOSITY_LOGGING
{
	LOG_MIN = 0,
	LOG_DEF,
	LOG_MAX
};

struct mission
{
	char *diff;
	char *title_num;
	char *title_name;
	char *part_num;
	char *part_name;
	char *obj[OBJECTIVES_MAX][2];
};

char *diff_char[OBJECTIVES_MAX] = {"a.", "b.", "c.", "d.", "e.", NULL};
int line_rows[] = {1330, 1428, 1527, 1625, 1724, 1822, 1921, 2020, 2119};

struct mission missions[MISSIONS_MAX] =
{
	/* Dam (Agent) */
	{
		"Agent",
		"1",
		"Arkangelsk",
		"i",
		"Dam",
		{
			{"Bungee jump from platform", NULL},
			{NULL, NULL}
		}
	},
	/* Facility (Agent) */
	{
		"Agent",
		"1",
		"Arkangelsk",
		"ii",
		"Facility",
		{
			{"Gain access to laboratory area", NULL},
			{"Rendezvous with 006", NULL},
			{"Destroy all tanks in bottling room", NULL},
			{"Minimize scientist casualties", NULL},
			{NULL, NULL}
		}
	},
	/* Runway (Agent) */
	{
		"Agent",
		"1",
		"Arkangelsk",
		"iii",
		"Runway",
		{
			{"Find plane ignition key", NULL},
			{"Escape in plane", NULL},
			{NULL, NULL}
		}
	},
	/* Surface i (Agent) */
	{
		"Agent",
		"2",
		"Severnaya",
		"i",
		"Surface",
		{
			{"Power down communications", "dish"},
			{"Enter base via ventilation tower", NULL},
			{NULL, NULL}
		}
	},
	/* Bunker i (Agent) */
	{
		"Agent",
		"2",
		"Severnaya",
		"ii",
		"Bunker",
		{
			{"Copy Goldeneye key and leave", "original"},
			{"Photograph main video screen", NULL},
			{NULL, NULL}
		}
	},
	/* Silo (Agent) */
	{
		"Agent",
		"3",
		"Kirghizstan",
		"i",
		"Launch Silo #4",
		{
			{"Photograph satellite", NULL},
			{"Minimize scientist casualties", NULL},
			{NULL, NULL}
		}
	},
	/* Frigate (Agent) */
	{
		"Agent",
		"4",
		"Monte Carlo",
		"i",
		"Frigate",
		{
			{"Rescue hostages", NULL},
			{"Plant tracking bug on helicopter", NULL},
			{NULL, NULL}
		}
	},
	/* Surface ii (Agent) */
	{
		"Agent",
		"5",
		"Severnaya",
		"i",
		"Surface",
		{
			{"Break communications link to", "bunker"},
			{"Gain entry to bunker", NULL},
			{NULL, NULL}
		}
	},
	/* Bunker ii (Agent) */
	{
		"Agent",
		"5",
		"Severnaya",
		"ii",
		"Bunker",
		{
			{"Recover CCTV tape", NULL},
			{"Escape with Natalya", NULL},
			{NULL, NULL}
		}
	},
	/* Statue (Agent) */
	{
		"Agent",
		"6",
		"St. Petersburg",
		"i",
		"Statue Park",
		{
			{"Contact Valentin", NULL},
			{"Confront and unmask Janus", NULL},
			{"Locate helicopter", NULL},
			{"Rescue Natalya", NULL},
			{"Find flight recorder", NULL},
			{NULL, NULL}
		}
	},
	/* Archives (Agent) */
	{
		"Agent",
		"6",
		"St. Petersburg",
		"ii",
		"Military Archives",
		{
			{"Escape from interrogation room", NULL},
			{"Find Natalya", NULL},
			{"Escape with Natalya", NULL},
			{NULL, NULL}
		}
	},
	/* Streets (Agent) */
	{
		"Agent",
		"6",
		"St. Petersburg",
		"iii",
		"Streets",
		{
			{"Pursue Ourumov and Natalya", NULL},
			{"Minimize civilian casualties", NULL},
			{NULL, NULL}
		}
	},
	/* Depot (Agent) */
	{
		"Agent",
		"6",
		"St. Petersburg",
		"iv",
		"Depot",
		{
			{"Locate Trevelyan's train", NULL},
			{NULL, NULL}
		}
	},
	/* Train (Agent) */
	{
		"Agent",
		"6",
		"St. Petersburg",
		"v",
		"Train",
		{
			{"Destroy brake units", NULL},
			{"Rescue Natalya", NULL},
			{"Escape to safety", NULL},
			{NULL, NULL}
		}
	},
	/* Jungle (Agent) */
	{
		"Agent",
		"7",
		"Cuba",
		"i",
		"Jungle",
		{
			{"Destroy drone guns", NULL},
			{"Eliminate Xenia", NULL},
			{"Escort Natalya to Janus base", NULL},
			{NULL, NULL}
		}
	},
	/* Control (Agent) */
	{
		"Agent",
		"7",
		"Cuba",
		"ii",
		"Control",
		{
			{"Protect Natalya", NULL},
			{"Disable Goldeneye satellite", NULL},
			{"Destroy armored mainframes", NULL},
			{NULL, NULL}
		}
	},
	/* Caverns (Agent) */
	{
		"Agent",
		"7",
		"Cuba",
		"iii",
		"Water Caverns",
		{
			{"Minimize scientist casualties", NULL},
			{NULL, NULL}
		}
	},
	/* Cradle (Agent) */
	{
		"Agent",
		"7",
		"Cuba",
		"iv",
		"Antenna Cradle",
		{
			{"Destroy control console", NULL},
			{"Settle the score with Trevelyan", NULL},
			{NULL, NULL}
		}
	},

	/* Dam (Secret Agent) */
	{
		"Secret Agent",
		"1",
		"Arkangelsk",
		"i",
		"Dam",
		{
			{"Neutralize all alarms", NULL},
			{"Bungee jump from platform", NULL},
			{NULL, NULL}
		}
	},
	/* Facility (Secret Agent) */
	{
		"Secret Agent",
		"1",
		"Arkangelsk",
		"ii",
		"Facility",
		{
			{"Gain access to laboratory area", NULL},
			{"Contact double agent", NULL},
			{"Rendezvous with 006", NULL},
			{"Destroy all tanks in bottling room", NULL},
			{"Minimize scientist casualties", NULL},
			{NULL, NULL}
		}
	},
	/* Runway (Secret Agent) */
	{
		"Secret Agent",
		"1",
		"Arkangelsk",
		"iii",
		"Runway",
		{
			{"Find plane ignition key", NULL},
			{"Destroy missile battery", NULL},
			{"Escape in plane", NULL},
			{NULL, NULL}
		}
	},
	/* Surface i (Secret Agent) */
	{
		"Secret Agent",
		"2",
		"Severnaya",
		"i",
		"Surface",
		{
			{"Power down communications", "dish"},
			{"Obtain safe key", NULL},
			{"Steal building plans", NULL},
			{"Enter base via ventilation tower", NULL},
			{NULL, NULL}
		}
	},
	/* Bunker i (Secret Agent) */
	{
		"Secret Agent",
		"2",
		"Severnaya",
		"ii",
		"Bunker",
		{
			{"Disrupt all surveillance equipment", NULL},
			{"Copy Goldeneye key and leave", "original"},
			{"Photograph main video screen", NULL},
			{NULL, NULL}
		}
	},
	/* Silo (Secret Agent) */
	{
		"Secret Agent",
		"3",
		"Kirghizstan",
		"i",
		"Launch Silo #4",
		{
			{"Photograph satellite", NULL},
			{"Obtain telemetric data", NULL},
			{"Retrieve satellite circuitry", NULL},
			{"Minimize scientist casualties", NULL},
			{NULL, NULL}
		}
	},
	/* Frigate (Secret Agent) */
	{
		"Secret Agent",
		"4",
		"Monte Carlo",
		"i",
		"Frigate",
		{
			{"Rescue hostages", NULL},
			{"Disarm bridge bomb", NULL},
			{"Disarm engine room bomb", NULL},
			{"Plant tracking bug on helicopter", NULL},
			{NULL, NULL}
		}
	},
	/* Surface ii (Secret Agent) */
	{
		"Secret Agent",
		"5",
		"Severnaya",
		"i",
		"Surface",
		{
			{"Break communications link to", "bunker"},
			{"Disable Spetznaz support aircraft", NULL},
			{"Gain entry to bunker", NULL},
			{NULL, NULL}
		}
	},
	/* Bunker ii (Secret Agent) */
	{
		"Secret Agent",
		"5",
		"Severnaya",
		"ii",
		"Bunker",
		{
			{"Compare staff / casualty lists", NULL},
			{"Recover CCTV tape", NULL},
			{"Disable all security cameras", NULL},
			{"Escape with Natalya", NULL},
			{NULL, NULL}
		}
	},
	/* Statue (Secret Agent) */
	{
		"Secret Agent",
		"6",
		"St. Petersburg",
		"i",
		"Statue Park",
		{
			{"Contact Valentin", NULL},
			{"Confront and unmask Janus", NULL},
			{"Locate helicopter", NULL},
			{"Rescue Natalya", NULL},
			{"Find flight recorder", NULL},
			{NULL, NULL}
		}
	},
	/* Archives (Secret Agent) */
	{
		"Secret Agent",
		"6",
		"St. Petersburg",
		"ii",
		"Military Archives",
		{
			{"Escape from interrogation room", NULL},
			{"Find Natalya", NULL},
			{"Recover helicopter black box", NULL},
			{"Escape with Natalya", NULL},
			{NULL, NULL}
		}
	},
	/* Streets (Secret Agent) */
	{
		"Secret Agent",
		"6",
		"St. Petersburg",
		"iii",
		"Streets",
		{
			{"Contact Valentin", NULL},
			{"Pursue Ourumov and Natalya", NULL},
			{"Minimize civilian casualties", NULL},
			{NULL, NULL}
		}
	},
	/* Depot (Secret Agent) */
	{
		"Secret Agent",
		"6",
		"St. Petersburg",
		"iv",
		"Depot",
		{
			{"Destroy computer network", NULL},
			{"Obtain safe key", NULL},
			{"Recover helicopter blueprints", NULL},
			{"Locate Trevelyan's train", NULL},
			{NULL, NULL}
		}
	},
	/* Train (Secret Agent) */
	{
		"Secret Agent",
		"6",
		"St. Petersburg",
		"v",
		"Train",
		{
			{"Destroy brake units", NULL},
			{"Rescue Natalya", NULL},
			{"Locate Janus secret base", NULL},
			{"Escape to safety", NULL},
			{NULL, NULL}
		}
	},
	/* Jungle (Secret Agent) */
	{
		"Secret Agent",
		"7",
		"Cuba",
		"i",
		"Jungle",
		{
			{"Destroy drone guns", NULL},
			{"Eliminate Xenia", NULL},
			{"Blow up ammo dump", NULL},
			{"Escort Natalya to Janus base", NULL},
			{NULL, NULL}
		}
	},
	/* Control (Secret Agent) */
	{
		"Secret Agent",
		"7",
		"Cuba",
		"ii",
		"Control",
		{
			{"Protect Natalya", NULL},
			{"Disable Goldeneye satellite", NULL},
			{"Destroy armored mainframes", NULL},
			{NULL, NULL}
		}
	},
	/* Caverns (Secret Agent) */
	{
		"Secret Agent",
		"7",
		"Cuba",
		"iii",
		"Water Caverns",
		{
			{"Destroy inlet pump controls", NULL},
			{"Destroy outlet pump controls", NULL},
			{"Destroy master pump console", NULL},
			{"Minimize scientist casualties", NULL},
			{NULL, NULL}
		}
	},
	/* Cradle (Secret Agent) */
	{
		"Secret Agent",
		"7",
		"Cuba",
		"iv",
		"Antenna Cradle",
		{
			{"Destroy control console", NULL},
			{"Settle the score with Trevelyan", NULL},
			{NULL, NULL}
		}
	},
	/* Aztec (Secret Agent) */
	{
		"Secret Agent",
		"8",
		"Teotihuaca'n",
		"i",
		"Aztec Complex",
		{
			{"Reprogram shuttle guidance", NULL},
			{"Launch shuttle", NULL},
			{NULL, NULL}
		}
	},

	/* Dam (00 Agent) */
	{
		"00 Agent",
		"1",
		"Arkangelsk",
		"i",
		"Dam",
		{
			{"Neutralize all alarms", NULL},
			{"Install covert modem", NULL},
			{"Intercept data backup", NULL},
			{"Bungee jump from platform", NULL},
			{NULL, NULL}
		}
	},
	/* Facility (00 Agent) */
	{
		"00 Agent",
		"1",
		"Arkangelsk",
		"ii",
		"Facility",
		{
			{"Gain access to laboratory area", NULL},
			{"Contact double agent", NULL},
			{"Rendezvous with 006", NULL},
			{"Destroy all tanks in bottling room", NULL},
			{"Minimize scientist casualties", NULL},
			{NULL, NULL}
		}
	},
	/* Runway (00 Agent) */
	{
		"00 Agent",
		"1",
		"Arkangelsk",
		"iii",
		"Runway",
		{
			{"Find plane ignition key", NULL},
			{"Destroy heavy gun emplacements", NULL},
			{"Destroy missile battery", NULL},
			{"Escape in plane", NULL},
			{NULL, NULL}
		}
	},
	/* Surface i (00 Agent) */
	{
		"00 Agent",
		"2",
		"Severnaya",
		"i",
		"Surface",
		{
			{"Power down communications", "dish"},
			{"Obtain safe key", NULL},
			{"Steal building plans", NULL},
			{"Enter base via ventilation tower", NULL},
			{NULL, NULL}
		}
	},
	/* Bunker i (00 Agent) */
	{
		"00 Agent",
		"2",
		"Severnaya",
		"ii",
		"Bunker",
		{
			{"Disrupt all surveillance equipment", NULL},
			{"Copy Goldeneye key and leave", "original"},
			{"Get personnel to activate", "computer"},
			{"Download data from computer", NULL},
			{"Photograph main video screen", NULL},
			{NULL, NULL}
		}
	},
	/* Silo (00 Agent) */
	{
		"00 Agent",
		"3",
		"Kirghizstan",
		"i",
		"Launch Silo #4",
		{
			{"Plant bombs in fuel rooms", NULL},
			{"Photograph satellite", NULL},
			{"Obtain telemetric data", NULL},
			{"Retrieve satellite circuitry", NULL},
			{"Minimize scientist casualties", NULL},
			{NULL, NULL}
		}
	},
	/* Frigate (00 Agent) */
	{
		"00 Agent",
		"4",
		"Monte Carlo",
		"i",
		"Frigate",
		{
			{"Rescue hostages", NULL},
			{"Disarm bridge bomb", NULL},
			{"Disarm engine room bomb", NULL},
			{"Plant tracking bug on helicopter", NULL},
			{NULL, NULL}
		}
	},
	/* Surface ii (00 Agent) */
	{
		"00 Agent",
		"5",
		"Severnaya",
		"i",
		"Surface",
		{
			{"Disrupt all surveillance equipment", NULL},
			{"Break communications link to", "bunker"},
			{"Disable Spetznaz support aircraft", NULL},
			{"Gain entry to bunker", NULL},
			{NULL, NULL}
		}
	},
	/* Bunker ii (00 Agent) */
	{
		"00 Agent",
		"5",
		"Severnaya",
		"ii",
		"Bunker",
		{
			{"Compare staff / casualty lists", NULL},
			{"Recover CCTV tape", NULL},
			{"Disable all security cameras", NULL},
			{"Recover Goldeneye operations", "manual"},
			{"Escape with Natalya", NULL},
			{NULL, NULL}
		}
	},
	/* Statue (00 Agent) */
	{
		"00 Agent",
		"6",
		"St. Petersburg",
		"i",
		"Statue Park",
		{
			{"Contact Valentin", NULL},
			{"Confront and unmask Janus", NULL},
			{"Locate helicopter", NULL},
			{"Rescue Natalya", NULL},
			{"Find flight recorder", NULL},
			{NULL, NULL}
		}
	},
	/* Archives (00 Agent) */
	{
		"00 Agent",
		"6",
		"St. Petersburg",
		"ii",
		"Military Archives",
		{
			{"Escape from interrogation room", NULL},
			{"Find Natalya", NULL},
			{"Recover helicopter black box", NULL},
			{"Escape with Natalya", NULL},
			{NULL, NULL}
		}
	},
	/* Streets (00 Agent) */
	{
		"00 Agent",
		"6",
		"St. Petersburg",
		"iii",
		"Streets",
		{
			{"Contact Valentin", NULL},
			{"Pursue Ourumov and Natalya", NULL},
			{"Minimize civilian casualties", NULL},
			{NULL, NULL}
		}
	},
	/* Depot (00 Agent) */
	{
		"00 Agent",
		"6",
		"St. Petersburg",
		"iv",
		"Depot",
		{
			{"Destroy illegal arms cache", NULL},
			{"Destroy computer network", NULL},
			{"Obtain safe key", NULL},
			{"Recover helicopter blueprints", NULL},
			{"Locate Trevelyan's train", NULL},
			{NULL, NULL}
		}
	},
	/* Train (00 Agent) */
	{
		"00 Agent",
		"6",
		"St. Petersburg",
		"v",
		"Train",
		{
			{"Destroy brake units", NULL},
			{"Rescue Natalya", NULL},
			{"Locate Janus secret base", NULL},
			{"Crack Boris' password", NULL},
			{"Escape to safety", NULL},
			{NULL, NULL}
		}
	},
	/* Jungle (00 Agent) */
	{
		"00 Agent",
		"7",
		"Cuba",
		"i",
		"Jungle",
		{
			{"Destroy drone guns", NULL},
			{"Eliminate Xenia", NULL},
			{"Blow up ammo dump", NULL},
			{"Escort Natalya to Janus base", NULL},
			{NULL, NULL}
		}
	},
	/* Control (00 Agent) */
	{
		"00 Agent",
		"7",
		"Cuba",
		"ii",
		"Control",
		{
			{"Protect Natalya", NULL},
			{"Disable Goldeneye satellite", NULL},
			{"Destroy armored mainframes", NULL},
			{NULL, NULL}
		}
	},
	/* Caverns (00 Agent) */
	{
		"00 Agent",
		"7",
		"Cuba",
		"iii",
		"Water Caverns",
		{
			{"Destroy inlet pump controls", NULL},
			{"Destroy outlet pump controls", NULL},
			{"Destroy master pump console", NULL},
			{"Use radio to contact Jack Wade", NULL},
			{"Minimize scientist casualties", NULL},
			{NULL, NULL}
		}
	},
	/* Cradle (00 Agent) */
	{
		"00 Agent",
		"7",
		"Cuba",
		"iv",
		"Antenna Cradle",
		{
			{"Destroy control console", NULL},
			{"Settle the score with Trevelyan", NULL},
			{NULL, NULL}
		}
	},
	/* Aztec (00 Agent) */
	{
		"00 Agent",
		"8",
		"Teotihuaca'n",
		"i",
		"Aztec Complex",
		{
			{"Reprogram shuttle guidance", NULL},
			{"Launch shuttle", NULL},
			{NULL, NULL}
		}
	},
	/* Egypt (00 Agent) */
	{
		"00 Agent",
		"9",
		"el-Saghira",
		"i",
		"Egyptian Temple",
		{
			{"Recover the golden gun", NULL},
			{"Defeat Baron Samedi?", NULL},
			{NULL, NULL}
		}
	},

	/* End of struct */
	{
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		{
			{NULL, NULL}
		}
	}
};
