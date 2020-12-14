#define MISSIONS_A_MAX 18
#define MISSIONS_SA_MAX 19
#define MISSIONS_00A_MAX 20
#define OBJECTIVES_MAX (OBJ_MAX + 1)

enum LEVEL_SEQUENCE
{
	LVL_DAM,
	LVL_FACILITY,
	LVL_RUNWAY,
	LVL_SURFACE1,
	LVL_BUNKER1,
	LVL_SILO,
	LVL_FRIGATE,
	LVL_SURFACE2,
	LVL_BUNKER2,
	LVL_STATUE,
	LVL_ARCHIVES,
	LVL_STREETS,
	LVL_DEPOT,
	LVL_TRAIN,
	LVL_JUNGLE,
	LVL_CONTROL,
	LVL_CAVERNS,
	LVL_CRADLE,
	LVL_AZTEC,
	LVL_EGYPT
};

enum DIFFICULTY
{
	DIFF_A = 0,
	DIFF_SA,
	DIFF_00A,
	DIFF_007,
	DIFF_NULL = -1
};

enum OBJECTIVES
{
	OBJ_A = 0,
	OBJ_B,
	OBJ_C,
	OBJ_D,
	OBJ_E,
	OBJ_MAX
};

struct objective
{
	char line1[64];
	char line2[64];
};

struct mission
{
	char diff[32];
	char title[32];
	char part[32];
	struct objective obj[OBJECTIVES_MAX];
};

char *diff_char[OBJECTIVES_MAX] = {"a.", "b.", "c.", "d.", "e.", "\0"};
int line_rows[] = {1330, 1428, 1527, 1625, 1724, 1822, 1921, 2020, 2119};

struct mission missions[MISSIONS_A_MAX + MISSIONS_SA_MAX + MISSIONS_00A_MAX + 1] =
{
	/* Dam (Agent) */
	{
		"Agent: James Bond",
		"Mission 1: Arkangelsk",
		"Part i: Dam",
		{
			{"Bungee jump from platform", "\0"}
		}
	},
	/* Facility (Agent) */
	{
		"Agent: James Bond",
		"Mission 1: Arkangelsk",
		"Part ii: Facility",
		{
			{"Gain access to laboratory area", "\0"},
			{"Rendezvous with 006", "\0"},
			{"Destroy all tanks in bottling room", "\0"},
			{"Minimize scientist casualties", "\0"}
		}
	},
	/* Runway (Agent) */
	{
		"Agent: James Bond",
		"Mission 1: Arkangelsk",
		"Part iii: Runway",
		{
			{"Find plane ignition key", "\0"},
			{"Escape in plane", "\0"}
		}
	},
	/* Surface i (Agent) */
	{
		"Agent: James Bond",
		"Mission 2: Severnaya",
		"Part i: Surface",
		{
			{"Power down communications", "dish"},
			{"Enter base via ventilation tower", "\0"}
		}
	},
	/* Bunker i (Agent) */
	{
		"Agent: James Bond",
		"Mission 2: Severnaya",
		"Part ii: Bunker",
		{
			{"Copy Goldeneye key and leave", "original"},
			{"Photograph main video screen", "\0"}
		}
	},
	/* Silo (Agent) */
	{
		"Agent: James Bond",
		"Mission 3: Kirghizstan",
		"Part i: Launch Silo #4",
		{
			{"Photograph satellite", "\0"},
			{"Minimize scientist casualties", "\0"}
		}
	},
	/* Frigate (Agent) */
	{
		"Agent: James Bond",
		"Mission 4: Monte Carlo",
		"Part i: Frigate",
		{
			{"Rescue hostages", "\0"},
			{"Plant tracking bug on helicopter", "\0"}
		}
	},
	/* Surface ii (Agent) */
	{
		"Agent: James Bond",
		"Mission 5: Severnaya",
		"Part i: Surface",
		{
			{"Break communications link to", "bunker"},
			{"Gain entry to bunker", "\0"}
		}
	},
	/* Bunker ii (Agent) */
	{
		"Agent: James Bond",
		"Mission 5: Severnaya",
		"Part ii: Bunker",
		{
			{"Recover CCTV tape", "\0"},
			{"Escape with Natalya", "\0"}
		}
	},
	/* Statue (Agent) */
	{
		"Agent: James Bond",
		"Mission 6: St. Petersburg",
		"Part i: Statue Park",
		{
			{"Contact Valentin", "\0"},
			{"Confront and unmask Janus", "\0"},
			{"Locate helicopter", "\0"},
			{"Rescue Natalya", "\0"},
			{"Find flight recorder", "\0"}
		}
	},
	/* Archives (Agent) */
	{
		"Agent: James Bond",
		"Mission 6: St. Petersburg",
		"Part ii: Military Archives",
		{
			{"Escape from interrogation room", "\0"},
			{"Find Natalya", "\0"},
			{"Escape with Natalya", "\0"}
		}
	},
	/* Streets (Agent) */
	{
		"Agent: James Bond",
		"Mission 6: St. Petersburg",
		"Part iii: Streets",
		{
			{"Pursue Ourumov and Natalya", "\0"},
			{"Minimize civilian casualties", "\0"}
		}
	},
	/* Depot (Agent) */
	{
		"Agent: James Bond",
		"Mission 6: St. Petersburg",
		"Part iv: Depot",
		{
			{"Locate Trevelyan's train", "\0"}
		}
	},
	/* Train (Agent) */
	{
		"Agent: James Bond",
		"Mission 6: St. Petersburg",
		"Part v: Train",
		{
			{"Destroy break units", "\0"},
			{"Rescue Natalya", "\0"},
			{"Escape to safety", "\0"}
		}
	},
	/* Jungle (Agent) */
	{
		"Agent: James Bond",
		"Mission 7: Cuba",
		"Part i: Jungle",
		{
			{"Destroy drone guns", "\0"},
			{"Eliminate Xenia", "\0"},
			{"Escort Natalya to Janus base", "\0"}
		}
	},
	/* Control (Agent) */
	{
		"Agent: James Bond",
		"Mission 7: Cuba",
		"Part ii: Control",
		{
			{"Protect Natalya", "\0"},
			{"Disable Goldeneye satellite", "\0"},
			{"Destroy armored mainframes", "\0"}
		}
	},
	/* Caverns (Agent) */
	{
		"Agent: James Bond",
		"Mission 7: Cuba",
		"Part iii: Water Caverns",
		{
			{"Minimize scientist casualties", "\0"}
		}
	},
	/* Cradle (Agent) */
	{
		"Agent: James Bond",
		"Mission 7: Cuba",
		"Part iv: Antenna Cradle",
		{
			{"Destroy control console", "\0"},
			{"Settle the score with Trevelyan", "\0"}
		}
	},

	/* Dam (Secret Agent) */
	{
		"Secret Agent: James Bond",
		"Mission 1: Arkangelsk",
		"Part i: Dam",
		{
			{"Neutralize all alarms", "\0"},
			{"Bungee jump from platform", "\0"}
		}
	},
	/* Facility (Secret Agent) */
	{
		"Secret Agent: James Bond",
		"Mission 1: Arkangelsk",
		"Part ii: Facility",
		{
			{"Gain access to laboratory area", "\0"},
			{"Contact double agent", "\0"},
			{"Rendezvous with 006", "\0"},
			{"Destroy all tanks in bottling room", "\0"},
			{"Minimize scientist casualties", "\0"}
		}
	},
	/* Runway (Secret Agent) */
	{
		"Secret Agent: James Bond",
		"Mission 1: Arkangelsk",
		"Part iii: Runway",
		{
			{"Find plane ignition key", "\0"},
			{"Destroy missile battery", "\0"},
			{"Escape in plane", "\0"}
		}
	},
	/* Surface i (Secret Agent) */
	{
		"Secret Agent: James Bond",
		"Mission 2: Severnaya",
		"Part i: Surface",
		{
			{"Power down communications", "dish"},
			{"Obtain safe key", "\0"},
			{"Steal building plans", "\0"},
			{"Enter base via ventilation tower", "\0"}
		}
	},
	/* Bunker i (Secret Agent) */
	{
		"Secret Agent: James Bond",
		"Mission 2: Severnaya",
		"Part ii: Bunker",
		{
			{"Disrupt all surveillance equipment", "\0"},
			{"Copy Goldeneye key and leave", "original"},
			{"Photograph main video screen", "\0"}
		}
	},
	/* Silo (Secret Agent) */
	{
		"Secret Agent: James Bond",
		"Mission 3: Kirghizstan",
		"Part i: Launch Silo #4",
		{
			{"Photograph satellite", "\0"},
			{"Obtain telemetric data", "\0"},
			{"Retrieve satellite circuity", "\0"},
			{"Minimize scientist casualties", "\0"}
		}
	},
	/* Frigate (Secret Agent) */
	{
		"Secret Agent: James Bond",
		"Mission 4: Monte Carlo",
		"Part i: Frigate",
		{
			{"Rescue hostages", "\0"},
			{"Disarm bridge bomb", "\0"},
			{"Disarm engine room bomb", "\0"},
			{"Plant tracking bug on helicopter", "\0"}
		}
	},
	/* Surface ii (Secret Agent) */
	{
		"Secret Agent: James Bond",
		"Mission 5: Severnaya",
		"Part i: Surface",
		{
			{"Break communications link to", "bunker"},
			{"Disable Spetznaz support aircraft", "\0"},
			{"Gain entry to bunker", "\0"}
		}
	},
	/* Bunker ii (Secret Agent) */
	{
		"Secret Agent: James Bond",
		"Mission 5: Severnaya",
		"Part ii: Bunker",
		{
			{"Compare staff / causality lists", "\0"},
			{"Recover CCTV tape", "\0"},
			{"Disable all security cameras", "\0"},
			{"Escape with Natalya", "\0"}
		}
	},
	/* Statue (Secret Agent) */
	{
		"Secret Agent: James Bond",
		"Mission 6: St. Petersburg",
		"Part i: Statue Park",
		{
			{"Contact Valentin", "\0"},
			{"Confront and unmask Janus", "\0"},
			{"Locate helicopter", "\0"},
			{"Rescue Natalya", "\0"},
			{"Find flight recorder", "\0"}
		}
	},
	/* Archives (Secret Agent) */
	{
		"Secret Agent: James Bond",
		"Mission 6: St. Petersburg",
		"Part ii: Military Archives",
		{
			{"Escape from interrogation room", "\0"},
			{"Find Natalya", "\0"},
			{"Recover helicopter black box", "\0"},
			{"Escape with Natalya", "\0"}
		}
	},
	/* Streets (Secret Agent) */
	{
		"Secret Agent: James Bond",
		"Mission 6: St. Petersburg",
		"Part iii: Streets",
		{
			{"Contact Valentin", "\0"},
			{"Pursue Ourumov and Natalya", "\0"},
			{"Minimize civilian casualties", "\0"}
		}
	},
	/* Depot (Secret Agent) */
	{
		"Secret Agent: James Bond",
		"Mission 6: St. Petersburg",
		"Part iv: Depot",
		{
			{"Destroy computer network", "\0"},
			{"Obtain safe key", "\0"},
			{"Recover helicopter blueprints", "\0"},
			{"Locate Trevelyan's train", "\0"}
		}
	},
	/* Train (Secret Agent) */
	{
		"Secret Agent: James Bond",
		"Mission 6: St. Petersburg",
		"Part v: Train",
		{
			{"Destroy break units", "\0"},
			{"Rescue Natalya", "\0"},
			{"Locate Janus secret base", "\0"},
			{"Escape to safety", "\0"}
		}
	},
	/* Jungle (Secret Agent) */
	{
		"Secret Agent: James Bond",
		"Mission 7: Cuba",
		"Part i: Jungle",
		{
			{"Destroy drone guns", "\0"},
			{"Eliminate Xenia", "\0"},
			{"Blow up ammo dump", "\0"},
			{"Escort Natalya to Janus base", "\0"}
		}
	},
	/* Control (Secret Agent) */
	{
		"Secret Agent: James Bond",
		"Mission 7: Cuba",
		"Part ii: Control",
		{
			{"Protect Natalya", "\0"},
			{"Disable Goldeneye satellite", "\0"},
			{"Destroy armored mainframes", "\0"}
		}
	},
	/* Caverns (Secret Agent) */
	{
		"Secret Agent: James Bond",
		"Mission 7: Cuba",
		"Part iii: Water Caverns",
		{
			{"Destroy inlet pump controls", "\0"},
			{"Destroy outlet pump controls", "\0"},
			{"Destroy master pump console", "\0"},
			{"Minimize scientist casualties", "\0"}
		}
	},
	/* Cradle (Secret Agent) */
	{
		"Secret Agent: James Bond",
		"Mission 7: Cuba",
		"Part iv: Antenna Cradle",
		{
			{"Destroy control console", "\0"},
			{"Settle the score with Trevelyan", "\0"}
		}
	},
	/* Aztec (Secret Agent) */
	{
		"Secret Agent: James Bond",
		"Mission 8: Teotihuaca'n",
		"Part i: Aztec Complex",
		{
			{"Reprogram shuttle guidance", "\0"},
			{"Launch shuttle", "\0"}
		}
	},

	/* Dam (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 1: Arkangelsk",
		"Part i: Dam",
		{
			{"Neutralize all alarms", "\0"},
			{"Install covert modem", "\0"},
			{"Intercept data backup", "\0"},
			{"Bungee jump from platform", "\0"}
		}
	},
	/* Facility (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 1: Arkangelsk",
		"Part ii: Facility",
		{
			{"Gain access to laboratory area", "\0"},
			{"Contact double agent", "\0"},
			{"Rendezvous with 006", "\0"},
			{"Destroy all tanks in bottling room", "\0"},
			{"Minimize scientist casualties", "\0"}
		}
	},
	/* Runway (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 1: Arkangelsk",
		"Part iii: Runway",
		{
			{"Find plane ignition key", "\0"},
			{"Destroy heavy gun emplacements", "\0"},
			{"Destroy missile battery", "\0"},
			{"Escape in plane", "\0"}
		}
	},
	/* Surface i (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 2: Severnaya",
		"Part i: Surface",
		{
			{"Power down communications", "dish"},
			{"Obtain safe key", "\0"},
			{"Steal building plans", "\0"},
			{"Enter base via ventilation tower", "\0"}
		}
	},
	/* Bunker i (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 2: Severnaya",
		"Part ii: Bunker",
		{
			{"Disrupt all surveillance equipment", "\0"},
			{"Copy Goldeneye key and leave", "original"},
			{"Get personnel to activate", "computer"},
			{"Download data from computer", "\0"},
			{"Photograph main video screen", "\0"}
		}
	},
	/* Silo (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 3: Kirghizstan",
		"Part i: Launch Silo #4",
		{
			{"Plant bombs in fuel rooms", "\0"},
			{"Photograph satellite", "\0"},
			{"Obtain telemetric data", "\0"},
			{"Retrieve satellite circuity", "\0"},
			{"Minimize scientist casualties", "\0"}
		}
	},
	/* Frigate (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 4: Monte Carlo",
		"Part i: Frigate",
		{
			{"Rescue hostages", "\0"},
			{"Disarm bridge bomb", "\0"},
			{"Disarm engine room bomb", "\0"},
			{"Plant tracking bug on helicopter", "\0"}
		}
	},
	/* Surface ii (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 5: Severnaya",
		"Part i: Surface",
		{
			{"Disrupt all surveillance equipment", "\0"},
			{"Break communications link to", "bunker"},
			{"Disable Spetznaz support aircraft", "\0"},
			{"Gain entry to bunker", "\0"}
		}
	},
	/* Bunker ii (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 5: Severnaya",
		"Part ii: Bunker",
		{
			{"Compare staff / causality lists", "\0"},
			{"Recover CCTV tape", "\0"},
			{"Disable all security cameras", "\0"},
			{"Recover Goldeneye operations", "manual"},
			{"Escape with Natalya", "\0"}
		}
	},
	/* Statue (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 6: St. Petersburg",
		"Part i: Statue Park",
		{
			{"Contact Valentin", "\0"},
			{"Confront and unmask Janus", "\0"},
			{"Locate helicopter", "\0"},
			{"Rescue Natalya", "\0"},
			{"Find flight recorder", "\0"}
		}
	},
	/* Archives (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 6: St. Petersburg",
		"Part ii: Military Archives",
		{
			{"Escape from interrogation room", "\0"},
			{"Find Natalya", "\0"},
			{"Recover helicopter black box", "\0"},
			{"Escape with Natalya", "\0"}
		}
	},
	/* Streets (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 6: St. Petersburg",
		"Part iii: Streets",
		{
			{"Contact Valentin", "\0"},
			{"Pursue Ourumov and Natalya", "\0"},
			{"Minimize civilian casualties", "\0"}
		}
	},
	/* Depot (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 6: St. Petersburg",
		"Part iv: Depot",
		{
			{"Destroy illegal arms cache", "\0"},
			{"Destroy computer network", "\0"},
			{"Obtain safe key", "\0"},
			{"Recover helicopter blueprints", "\0"},
			{"Locate Trevelyan's train", "\0"}
		}
	},
	/* Train (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 6: St. Petersburg",
		"Part v: Train",
		{
			{"Destroy break units", "\0"},
			{"Rescue Natalya", "\0"},
			{"Locate Janus secret base", "\0"},
			{"Crack Boris' password", "\0"},
			{"Escape to safety", "\0"}
		}
	},
	/* Jungle (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 7: Cuba",
		"Part i: Jungle",
		{
			{"Destroy drone guns", "\0"},
			{"Eliminate Xenia", "\0"},
			{"Blow up ammo dump", "\0"},
			{"Escort Natalya to Janus base", "\0"}
		}
	},
	/* Control (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 7: Cuba",
		"Part ii: Control",
		{
			{"Protect Natalya", "\0"},
			{"Disable Goldeneye satellite", "\0"},
			{"Destroy armored mainframes", "\0"}
		}
	},
	/* Caverns (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 7: Cuba",
		"Part iii: Water Caverns",
		{
			{"Destroy inlet pump controls", "\0"},
			{"Destroy outlet pump controls", "\0"},
			{"Destroy master pump console", "\0"},
			{"Use radio to contact Jack Wade", "\0"},
			{"Minimize scientist casualties", "\0"}
		}
	},
	/* Cradle (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 7: Cuba",
		"Part iv: Antenna Cradle",
		{
			{"Destroy control console", "\0"},
			{"Settle the score with Trevelyan", "\0"}
		}
	},
	/* Aztec (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 8: Teotihuaca'n",
		"Part i: Aztec Complex",
		{
			{"Reprogram shuttle guidance", "\0"},
			{"Launch shuttle", "\0"}
		}
	},
	/* Egypt (00 Agent) */
	{
		"00 Agent: James Bond",
		"Mission 9: el-Saghira",
		"Part i: Egyptian Temple",
		{
			{"Recover the golden gun", "\0"},
			{"Defeat Baron Samedi?", "\0"}
		}
	},

	/* End of struct */
	{
		"\0",
		"\0",
		"\0",
		{
			{"\0", "\0"}
		}
	}
};