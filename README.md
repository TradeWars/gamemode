# Trade Wars

Trade Wars is a free-roam, item-collection and combat oriented SA:MP gamemode.

The primary objective of the game is to make **money**. The world contains
randomly spawned **items** at over 8,000 locations, some harder to find than
others. These items range from common household junk to rare and unique
trinkets. A network of **vendors** across the world will pay good money for
quality items. Prices will fluctuate, driven by a simulated economy.

If prices are pretty low for your **Green Tinted, Engraved, 7.62mm AK-47** then
you can trade it with another player for another item you might make a quick
profit off. It would suck if the price of that AK-47 shot up the next day...

This gamemode aims to bring together the economic aspects of **Roleplay** and
the item hoarding of **Scavenge and Survive** with a side order of free-roam,
light RP and fun.

## Usage

### Get the Code

First get the repository and dependencies, either with `package get`:

```bash
# Recommended: run this inside a directory named TradeWars
sampctl package get TradeWars/gamemode
```

This will clone the project to your current directory if it's empty or it will
create a new directory named `gamemode` and clone there. After this, all
dependencies will be pulled and the source code will be ready to build.

Or you can use `git clone`:

```bash
git clone https://github.com/TradeWars/gamemode.git
cd gamemode
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
[here](https://github.com/TradeWars/warehouse) and you can simply download one
of the release binaries and run it.

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
[contributing guidelines](https://github.com/TradeWars/gamemode/blob/master/docs/CONTRIBUTING.md)
if you are interested in contributing to this project. If you are interested in
contributing regularly, contact me on Discord and I will give you push access to
the repository.
