# Push_Swap

This project will make you sort data on a stack with the help of another stack, using the lowest possible number of actions.

## Instructions

- sa : swap a - swap the first two elements of pile A.
- sb : swap b - swap the first two elements of pile B.
- ss : sa and sb simultaneously.
- pa : push a - Take out the first element of pile A and put it on top of pile B.
- pb : push b - Take out the first element of pile B and put it on top of pile A.
- ra : rotate a - Shift all element of pile A by 1 toward the top. The first element becomes the last.
- rb : rotate b - Shift all element of pile B by 1 toward the top. The first element becomes the last.
- rr : ra and rb simultaneously.
- rra : reverse rotate a - Shift all element of pile A by 1 toward the bottom. The last element becomes the first.
- rrb : reverse rotate b - Shift all element of pile B by 1 toward the bottom. The last element becomes the first.
- rrr : rra and rrb simultaneously.

## Usage

- git clone the repository
```bash
make
```
```bash
ARG=[random values]; ./push_swap $ARG | ./checker -s -c $ARG

-s: show stacks in real time
-c: colors
-v: debugging mode
```
## Example
![alt text](https://github.com/Conanyedo/Push_swap/blob/master/Screen1.png?raw=true)
![alt text](https://github.com/Conanyedo/Push_swap/blob/master/Screen2.png?raw=true)
