MEMORY
{
  FLASH (rx) : ORIGIN = 0x00007000, LENGTH = 4k
  RAM (rwx) : ORIGIN = 0x10000000, LENGTH = 8k
}

INCLUDE rules.ld
