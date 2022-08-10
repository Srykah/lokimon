# Models

Models are classes (or simple structs) that hold the game data and are responsible for maintaining its invariants.

## Data

Models that are loaded at the beginning of the game and that are not supposed to change thereafter. Use GameData to handle them.

## View models

Models that hold view information (textures, sfx, etc.), loaded on-demand only based on the information contained in the game data. They typically do not change after being loaded.

## Gameplay models

Models that hold the current game state. They reference models from the game data wherever possible, through means of a pointer or an index. They are meant to change during normal gameplay.

## Other

Other models that are not directly gameplay-related, but might change during gameplay.
