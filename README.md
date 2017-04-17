# neural-mono
DWRAON based organisms running on Mono

## Draft
### will be tweaked to fit controller limits
A minimal version implementation of script bots, running as small dots on the OpenMono microcontroller.

- Agent
Moves based on minimal neural network and learns through evolution - can't have expensive math here, - and eats food elements randomly popping into the environment.
When an agents eats food it reproduces and passes on network waits with weighted mutation.
Dies when specified time has passed or from not getting food.

- Food
It's just food; randomly spawned in the environment when the global *food supply* is below 4 or something.

## Mono

```
32bit ARM M3
80MHz
220x176 display
64KB SRAM
2KB ROM
256KB flash
```