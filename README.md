# EncodingByFractal


## Usage
```
gcc zip.c -o zzz
```
First you have to compile it
```
./zzz {inputFile} {outPutFile} {key}
```
One thing to be noted here is that the key must be a number for now. Later it could accept any string in UTF-8 hopefully
Or you can use it like this, and follow the instruction
``` 
./zzz
```
## How it works
![img](http://www.sciweavers.org/tex2img.php?eq=x_%7Bn%2B1%7D%3Dr%281-x_n%29x_n&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0[/img])
### One way function (Secure)
For computationally bounded adversaries, it is impossible to predict the next x even when they know the first n x and given they know this formula.
And we just need to remember r and first x, and then we are able to calculate everything we need. 
For this program, the first x has a default value of 0.4 for convenience. And it is still secure if the adversary does not know the r
### XOR (correctness)
Using XOR here could make Decode and Encode to be same program which would make life easier

# More proves and graphs will be given later
Information of this equation could be found at:
https://www.youtube.com/watch?v=ovJcsL7vyrk

For Chinese User:
https://www.bilibili.com/video/BV1B7411W7LB
