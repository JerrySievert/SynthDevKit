# SynthDevKit

SynthDevKit is a set of utilities for development of software and hardware synthesizers.

All effort is made to test correctness and functionality.  SynthDevKit is meant
to be a dependency, not a stand-alone project.

## Building and Testing

SynthDevKit lives on [GitHub](https://github.com/JerrySievert/SynthDevKit).

### Building

```
$ git clone https://github.com/JerrySievert/SynthDevKit.git
$ cd SynthDevKit
$ make
```

This will compile the source, ready for direct inclusion in your project.

### Testing

SynthDevKit includes tests that check the functionality of the modules.

Building the test runner is simple, and running with the `-s` flag will run the
tests in `spec` mode.

```
$ make test
$ ./testrunner -s
```
