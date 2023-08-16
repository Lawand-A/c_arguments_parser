# c_arguments_parser
To parse arguments in c programm with no specific order and with check for the types and the argument spelling.

<h3>How to run</h3>:
```bash
gcc arguments.c -o program
```

<h4>Those arguments should work:</h4>

```bash
./program -i <String>
./program -w <String>
./program -length <Integer>
./program -i <String> -length <Integer>
./program -length <Integer> -w <String>
./program -w <String> -i <String>
./program -i <String> -length <Integer> -w <String>
./program -length <Integer> -i <String> -w <String>
./program -w <String> -length <Integer> -i <String>
./program -i <String> -w <String> -length <Integer>
```

<h4>Those arguments should NOT work:</h4>

```bash
./program -ii <String>
./program -length <String>
./program -leth <Integer>
./program i <String>   //missing '-'
./program -length <Integer> -i <String> -w <String> -length <Integer>  //duplicated argument
./program -w <String> -length <Integer> -i <String>
./program -i <String> -w <String> -length <Integer>
```

