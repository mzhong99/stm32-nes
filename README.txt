================================================================================
NES Emulator
================================================================================
 - Identify and subdivide core subsystem components:
   - CoreProcessor (NES) -> CPU, APU, PPU, ROM loading, mapper
   - Everything needs to be statically allocated - we are porting this to a
     microcontroller and cannot afford nondeterministic behavior
   - Input -> keyboard, controller
   - Renderer -> sound, video
 - Statically compile everything into a single binary
   - Potential for `*.a` files
 - Of course you should have a unit test library, probably something simple in C
   is sufficient

