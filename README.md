# Spell Checker with Unified CMake Build System

This project introduces a spell-checking utility implemented in C with a unified build system leveraging CMake. It includes features for efficient word lookup using hash tables and a streamlined build process with integrated cleaning functionality.

---

## Features

### Unified CMakeLists.txt
- Combines the functionality of a Makefile and CMake configuration.
- Supports build, clean, and executable management in a cross-platform manner.
- Ensures maintainability and extensibility for future enhancements.

### Spell Checker
- Efficient spell-checking utility written in C.
- Uses a hash table for quick dictionary lookups.
- Implements:
  - `SpellChecker.c`: Core logic for spell checking.
  - `SpellChecker.h`: Function declarations.

### Custom Clean Target
- Removes build artifacts and temporary files via the `clean` target.

---

## Installation and Usage

### Build the Project
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Run the Spell Checker
To check a text file for spelling errors:
```bash
./SpellChecker <text_file_to_check>
```

### Clean Build Files
```bash
cmake --build . --target clean
```

---

## Configuration Files

### `allow.txt`
Contains words to be accepted during spell-checking. For example:
```
ctype
fclose
fopen
fscanf
ifndef
malloc
```

### `patterns.txt`
Defines patterns to ignore. For example:
```
^\s*#include\s*(?:<.*?>|".*?")
(?:^|[\t ,>"'`=(])-(?:(?:J-|)[DPWXY]|[Llf])(?=[A-Z]{2,}|[A-Z][a-z]|[a-z]{2,})
```

---

## Integration with GitHub Actions

This project integrates with GitHub Actions for automated spell-checking. The workflow:
1. Checks spelling in code and text files.
2. Flags unrecognized words or patterns.
3. Suggests updates to `allow.txt` and `patterns.txt` for resolution.

---

## Future Enhancements
- **Error Correction**: Implement suggestions using Levenshtein distance.
- **Multi-threading**: Optimize for performance in larger files.
- **Advanced Configuration**: Enhance `CMakeLists.txt` for more flexible builds.

---

## Contributing
Contributions are welcome! Please:
1. Fork the repository.
2. Create a feature branch.
3. Submit a pull request with a clear description of your changes.

---

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Acknowledgments
Special thanks to the contributors and maintainers of the [check-spelling](https://github.com/check-spelling/check-spelling) GitHub Action for their robust spell-checking automation.
