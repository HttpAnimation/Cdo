# CDo/stable

CDo/stable is a groundbreaking sub-operating system designed to run on a host OS while allowing users to manipulate data independently of the host system. With its innovative features and user-friendly interface, CDo/stable provides a seamless experience for managing files and executing commands without affecting the underlying host OS.

![Usage](nEtYpNq.png)

## Commands

### read
The `read` command functions similarly to `cat` on Unix systems, allowing users to display the contents of a file.
```cdo
CDo> read compile.bash
gcc -o Cdo cdo.c
```

### echo
The `echo` command repeats a message sent to the application.
```cdo
CDo> echo Hello, World!
Hello, World!
```

### ls
Use the `ls` command to list the files in the current directory.
```cdo
CDo> ls
file1
folder1
file2
file3
...
file69
```

### clear
The `clear` command clears the console.
```cdo
CDo> clear
```

### exit
`exit` allows you to exit the CDo environment and return to the host OS.
```cdo
CDo> exit
$/
```

### host
Execute host commands using the `host` command.
```cdo
CDo> host neofetch
[Output of neofetch command would appear here]
```

### help
Display a help message with the `help` command.
```cdo
CDo> help
[Message about help would appear here]
```

### mkdir
Create a new directory using the `mkdir` command.
```cdo
CDo> mkdir folderone
CDo> ls
...
folderone
...
```

### ping
Ping a URL to retrieve data.
```cdo
CDo> ping google.com
Error: Invalid URL format.
CDo> ping https://google.com
[Output of ping command would appear here]
```

### v
Check the version of CDo/stable using the `v` command.
```cdo
CDo> v
Version is 69 - nice
```