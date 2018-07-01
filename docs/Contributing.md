# Contributing

## Adding Things

This mode may differ slightly to other Pawn codebases out there. It's first and
foremost an experiment and testing ground for new development methods.

That being said, I do not wish to discourage anyone from contributing! The whole
point of this new project structure for Pawn is to make the collaboration
process on Pawn projects smoother.

### Branches

If you have push access to the repository, this section is very important.

This project makes use of
[**Git Flow**](https://nvie.com/posts/a-successful-git-branching-model/) as a
model for managing branches.

You should read the above link for more information. In short:

- `master` branch only contains working code that will go live
- `hotfix` branches fix minor problems in `master`
- `develop` branch contains latest experimental code
- `feature-*` branches implement and test new features

See below for a brief overview of the workflow for implementing something new.

### New Features

When adding a new feature, first you must create a new branch for it _from_ the
`develop` branch:

```bash
git checkout develop
git checkout -b feature-newthing
```

The branch name must begin with `feature-`, all lowercase using dashes as
separators, for example: `feature-item-shop`.

Now create a new package for it somewhere in the `/gamemodes/sandbox/`
directory. The package should have a brief `README.md` file describing the
feature.

Once you've done that, as long as you follow the style guide, and a feature
proposal in the issues section you can write the code and implement the feature.

When you've done and the code is ready to be merged, merge it into `develop` so
it can be staged with other experimental features and code. Once it has been
deemed safe, a project lead will merge `develop` into `master` and it will be
released onto the live server.

### Tutorials

There are tutorials and documentation available for the codebase inside the
`docs/` directory on the repository.
