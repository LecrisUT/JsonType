# JsonType

[![CI Status][ci-badge]][ci-link]
[![Codecov Status][codecov-badge]][codecov-link]

[![Documentation Status][rtd-badge]][rtd-link]
![CMake Status][cmake-badge]

<!-- SPHINX-START -->

Minimalistic project wrapping C++ container library to provide generic datastructure compatible with JSON, YAML, TOML.

This project provides only the Json-like type structure and manipulations. Parsing, formatting, validation, are outside
the scope of this project.

## Motivation

There are [various projects][projects] that parse and manipulate JSON, YAML, TOML data. However, all of these projects
have different type structure for their data type, making it difficult to design Json schema validation that would
be compatible with all of these projects. Thus, the aim of this project is to define the bottom-most common layer of
the data-structure that these all have in common.

## Wrappers

Ideally all other projects would inherit and expand the datastructure provided here, but that would require a wide
adoption of this project and refactoring of their projects. In the meantime, there are wrappers provided that provide
implicit converters from the upstream's Json data structure to this project's.

<!-- SPHINX-END -->

## License

This template project is licensed under MIT license.

[projects]: https://en.cppreference.com/w/cpp/links/libs#Configuration

[ci-badge]: https://github.com/LecrisUT/JsonType/actions/workflows/ci.yaml/badge.svg?branch=main&event=push
[rtd-badge]: https://readthedocs.org/projects/jsontype/badge/?version=latest
[codecov-badge]: https://codecov.io/gh/LecrisUT/JsonType/graph/badge.svg?token=UNUC8YOUCE
[cmake-badge]: https://img.shields.io/badge/CMake-3.25-blue?logo=data:image/svg%2bxml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIGRhdGEtbmFtZT0iTGF5ZXIgMiIgdmlld0JveD0iMCAwIDU0NS41IDU0NS45Ij48cGF0aCBkPSJNNTQ2IDUzNCAyODIgOWwzOSA0MzQgMjI1IDkxeiIgZGF0YS1uYW1lPSJyZWQgcmlnaHQiIHN0eWxlPSJmaWxsOiNmMzI3MzU7c3Ryb2tlLXdpZHRoOjAiLz48cGF0aCBkPSJNNTI1IDU0NiAxNzAgNDAzIDEgNTQ2aDUyNHoiIGRhdGEtbmFtZT0iZ3JlZW4gYm90dG9tIiBzdHlsZT0ic3Ryb2tlLXdpZHRoOjA7ZmlsbDojM2VhZTJiIi8+PHBhdGggZD0iTTI2MyAwIDAgNTIybDI4OC0yNDRMMjYzIDB6IiBkYXRhLW5hbWU9ImJsdWUgbGVmdCIgc3R5bGU9ImZpbGw6IzAwNjhjNztzdHJva2Utd2lkdGg6MCIvPjxwYXRoIGQ9Im0yOTEgMjk5LTEwNSA4OSAxMTcgNDgtMTItMTM3eiIgZGF0YS1uYW1lPSJncmF5IGNlbnRlciIgc3R5bGU9ImZpbGw6I2RjZTNlYztzdHJva2Utd2lkdGg6MCIvPjwvc3ZnPg==

[ci-link]: https://github.com/LecrisUT/JsonType/actions?query=branch%3Amain+event%3Apush
[rtd-link]: https://jsontype.readthedocs.io/en/latest/?badge=latest
[codecov-link]: https://codecov.io/gh/LecrisUT/JsonType
