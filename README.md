# Test log [windows]

## More info and test log [ubuntu] in Github.Actions: [![statusbadge](../../actions/workflows/buildtest.yaml/badge.svg?branch=main&event=pull_request)](../../actions/workflows/buildtest.yaml)

Build log (can be empty):
```
D:\a\itmo-comp-arch22-lab4-anbtrfl\itmo-comp-arch22-lab4-anbtrfl\easy.cpp:1:9: warning: '_CRT_SECURE_NO_WARNINGS' macro redefined [-Wmacro-redefined]
#define _CRT_SECURE_NO_WARNINGS
        ^
<command line>:1:9: note: previous definition is here
#define _CRT_SECURE_NO_WARNINGS 1
        ^
D:\a\itmo-comp-arch22-lab4-anbtrfl\itmo-comp-arch22-lab4-anbtrfl\easy.cpp:32:33: warning: format specifies type 'int *' but the argument has type 'long long *' [-Wformat]
    if (fscanf(inp, "%f%d", &R, &cnt) != 2) {
                       ~~       ^~~~
                       %lld
2 warnings generated.

```

Stdout+stderr (./omp4 0 in out):
```
OK [program completed with code 0]
    [STDERR]:  
    [STDOUT]: Time(2 thread(s)): 4.0796 ms

```
     
Stdout+stderr (./omp4 -1 in out):
```
OK [program completed with code 0]
    [STDERR]:  
    [STDOUT]: Time(1 thread(s)): 5.2708 ms

```

Input:
```
1 100000

```

Output 0:
```
3.140320
```

Output -1:
```
3.140120
```