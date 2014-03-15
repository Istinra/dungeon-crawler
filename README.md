Dungeon Crawler
===============

Wolfenstein 3D 90s style shooter/dungeon crawler where you fight through monsters and puzzles to get to the end.

The main goal was to experiment with the http://en.wikipedia.org/wiki/Ray_casting technique used in some of the original shooter games and to actually complete a game end to end.

Windowing:
  SDL
  
Graphics:
  Walls/Roof/Floor Draw using Ray Casting and some maths
  Sprites draw using some simple perspective maths
  
Sound:
  Using SDL sound with manual mixing
  
Loading/Content:
  Uses stb_image to load PNG files
  PNG images used to for:
    Textures
    Level Layout (Using RGBA challels to determine what block/entity goes into a space)
    Sprites
  
