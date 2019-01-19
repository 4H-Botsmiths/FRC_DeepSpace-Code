# Code of Conduct

This file will discuss the rules for what code should look like and do before pushing to the GIT Repository

## Syntaxing

### Keep it clean

* Use minimal whitespace between lines/functions
* No trailing whitespace at end of lines
* Comments must be useful and Safe For 4-H (no swearing)

```
random_call(0,0);               <- dont leave empty space
random_call(0,0); <- make sure there is no trailing spaces

//example of OK spacing:
run_this();

run_me();

//example of NOT OK spacing:
run_this();


run_me();
```

### Spacing

* All files must use Size 4 tab indentation
* Brakets go on the same line as the declaration

Tabs can be adjusted by doing: ctrl+shift+p => Indent Using Tabs => 4

Then, to change document to new indentation style, do ctrl+a => ctrl+k => ctrl+f

```
//example of OK braket usage:
if (something) {
    do_something();
}

if (something) { return 0; }

if (something) return 0; //this is preffered for if statements that are one-line-able

//example of NOT OK braket usage:
if (something)
{
    do_something();
}
```

## Debugging/testing

* make mark of what things you need to test for once code is pushed

```
//example

move_up(); //this should move the arm up
```