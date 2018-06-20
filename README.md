# samp-sandbox

[![sampctl](https://shields.southcla.ws/badge/sampctl-samp--sandbox-2f2f2f.svg?style=for-the-badge)](https://github.com/Southclaws/samp-sandbox)

A work in progress sandbox gamemode...

Come back later when it's more finished!

## Usage

### Get the Code

First get the repository and dependencies, either with `package get`:

```bash
sampctl package get Southclaws/samp-sandbox
```

This will clone the project to your current directory if it's empty or it will
create a new directory named `samp-sandbox` and clone there. After this, all
dependencies will be pulled and the source code will be ready to build.

Or you can use `git clone`:

```bash
git clone https://github.com/Southclaws/samp-sandbox.git
cd samp-sandbox
sampctl package ensure
```

This doesn't download the dependencies so you must run `package ensure` after
cloning.

### First Build

Once you have the code, make sure your terminal/editor is open to the project
directory then run a first build to make sure everything is working:

```bash
sampctl package build
```

The `master` branch should never have errors but may include warnings from time
to time.

### First Run

Now you've built the project, you must run the server once then close it to
automatically create any necessary files in `scriptfiles/`.

```bash
sampctl package run
# CTRL+C to close after initialisation has finished
```

This will, among other things, create the `settings.ini` file with default
values inside the `scriptfiles/` directory.

### Set Up Storage

This project currently uses [jsonstore.io](https://jsonstore.io) to store data.
Head over to the jsonstore.io website and click `Copy` to copy the endpoint to
the clipboard. You should get a long URL like
`https://www.jsonstore.io/5b91329ab4cb74da82490f9b6e8ca2542620c067507afd9af3164ca4c17033fe`.

Open up `scriptfiles/settings.ini` and paste the URL as the value to the
`endpoint` key.

You should now have something like:

```ini
...
endpoint=https://www.jsonstore.io/5b91329ab4cb74da82490f9b6e8ca2542620c067507afd9af3164ca4c17033fe
...
```

(There will likely be a lot more settings above and below the `endpoint` key.)

### Run

Now you can run the server with `sampctl package run` and connect to it via the
SA:MP client.

### Debug Logging

Throughout the code, there are debug logs that use
[Southclaws/samp-logger](https://github.com/Southclaws/samp-logger)'s `dbg`
function. Different modules and packages have named debuggers which you can
enable by adding an entry to the `debug` entry in `settings.ini`. For example,
if you wanted to activate `player` and `weapon` debug logs, you would write:

```ini
debug/0=player
debug/1=weapon
```

## Contributing

Please see the
[contributing guidelines](https://github.com/Southclaws/samp-sandbox/blob/master/.github/CONTRIBUTING.md)
if you are interested in contributing to this project. If you are interested in
contributing regularly, contact me on Discord and I will give you push access to
the repository.
