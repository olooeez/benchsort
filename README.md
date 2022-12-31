# benchsort

This is a tool for benchmarking the performance of different sorting algorithms. It is written in C and provides a command-line interface for specifying the input size and the algorithms to be compared.

## Project structure on GitHub

The project was done in phases, each one distinct from the other. With that in mind, i developed each phase in a branch. In this current branch, the available data structures are:

- `merge sort`
- `selection sort`
- `quick sort v1 (first item is the pivot)`
- `quick sort v2 (middle item is the pivot)`
- `quick sort v3 (median of three is the pivot)`
- `quick sort v4 (a random item is the pivot)`


## Requirements

- make
- gcc
- linux

## Usage

1. Download or clone the project.
2. Make the executable by running `make` at the root of the project.
3. Run the executable with `./bin/benchsort`.

## Contributing

If you have suggestions for improvements or want to report a bug, please open an issue or a pull request.

## License

This script is licensed under the GNU General Public License v3.0. See the [LICENSE](https://github.com/olooeez/benchsort/blob/phase-3/LICENSE) file for details.
