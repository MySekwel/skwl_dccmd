# skwl_dccmd

A Command Processor designed for discord-connector-plugin

## Dependencies

You need these dependencies on your gamemode (NOT IN THE INCLUDE FOLDER ITSELF)
- YSI Library:
`sampctl package install pawn-lang/YSI-Includes:v5.4.102`
- Discord Connector Plugin:
`sampctl package install maddinat0r/samp-discord-connector:v0.3.5`

## Installation

Simply install to your project:

```bash
sampctl package install MySekwel/skwl_dccmd
```

Define your prefix above the include:

```pawn
#define ZDC_PREFIX    "!" // Define your prefix before including the include
#include <z_dccmd>
```

## Usage

Copy the discord_bot_token format inside my pawn.json and add it to your pawn.json, don't forget the `extra`

```json
"extra": {
			"discord_bot_token": "changeme"
		}
```

## Testing

I've setup a test pwn file,
To test, just simply run the package:

```bash
sampctl package run
```