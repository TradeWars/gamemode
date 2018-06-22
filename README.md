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

### Build The Package

Once you have the code, make sure your terminal/editor is open to the project
directory then run a first build to make sure everything is working:

```bash
sampctl package build
```

The `master` branch should never have errors but may include warnings from time
to time.

### Set Up Storage

This project uses a custom backend for storing data. That project is available
[here](https://github.com/Southclaws/ScavengeSurviveCore) and you can simply
download one of the release binaries and run it.

By default, when you run the `ssc` executable, it will launch in "temporary
mode" which is a no-configuration setup and is instantly listening for
connections and will store data in-memory with no database. This allows you to
get up and running very quickly.

The default listen address is `:7788` so you should be able to access
`http://localhost:7788` via `curl` with the header `Authorization: cunning_fox`
which is the default temporary auth string.

### Run The Package

Now you can run the server with `sampctl package run` and connect to it via the
SA:MP client. When you connect for the first time, the game server will submit a
HTTP GET request to `http://localhost:7788/store/playerGet?name=<your username>`
which you should see on the `ssc` process log. If all goes well, you should see
two messages: one to acknowledge the request and another that logs the response
data.

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
