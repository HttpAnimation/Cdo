# Cdo/stable
A new type of os called a sub-os made to be ran on a host then be able to pick and byte data that won't effect the host os.

# Commands

## read
The read command will read out a file similer to cat on unix
```cdo
CDo> read compile.bash
gcc -o Cdo cdo.c
```

## echo
This will repeat a message sent to the app
```cdo
Cdo> echo Hello, World!
Hello, World!
```

## ls
This is will print current files in the dir enterd.
```cdo
Cdo> ls
file 1
folder 1
file 2
file 3
...
file 69
```

## clear
Clears the console.
```cdo
Cdo> clear
```

## exit
Exits the script into the host os
```cdo
Cdo> exit
$/
```

## host
Allows you to run host commands
```cdo
Cdo> host neofetch
Pretend theres a neofetch command here it would not copy write
```