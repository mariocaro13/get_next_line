# get_next_line
Custom GNL developed in 42 Madrid

## Main
The main folder contain:
- **main.c**: Main for test gnl.
- **Makefile**: Main **Makefile** for quick tests.
- **text.txt**: Sample text for test.

## **Makefile** Rules
- **make**: Compile the program and generate an ./gnl.
- **clean**: Remove binary objects.
- **fclean**: Call **clean** and remove ./gnl.
- **run**: Call ./gnl.
- **run bsize=n**: Call **run** and recompile the program with -D BUFFER_SIZE=n.
> [!NOTE]
> These rules are in **main/Makefile**, but I have added a **Makefile** for call each rule in the gnl folder.
