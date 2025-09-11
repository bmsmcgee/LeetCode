# Project Setup: Part One

## Task 1: Setup Project Folder

1. Navigate to the folder where we'll store the new project
2. Create a new directory called `express-recipes` and change into it

```bash
mkdir express-recipes
cd express-recipes
```

## Task 2: Create a `package.json` File

1. Turn the project into an `npm` package by running the following command:

```bash
npm init
```

After executing the commands provided, an  `npm` package is created.

<img width="936" height="435" alt="image" src="https://github.com/user-attachments/assets/7ba8fa43-ab9f-45e2-a25c-9c52e2909960" />

The term _package_ refers to a file or directory described by a `package.json` file. A package must contain a `package.json` file to be published to the `npm` registry.

### What Happens when we Run the Command Above?

The command above loads a questionnaire containing a series of questions about how we would like to configure our package. It asks for the project name, licenses, version, and so on.

Press _Enter_ on every question to accept the defaults.

  > **Note**: Once the command `npm init --yes` is executed, `npm` will create a default `package.json` file using information extracted from the current directory. This option is seldom used since developers often want to customize the manifest instead of using default values.

A manifest file called package.json will be created:

<img width="935" height="432" alt="image" src="https://github.com/user-attachments/assets/2f9ca623-55e5-45e8-8ad2-fdc11dadd6b3" />

The `package.json` file will specify versions of a package that our project can use based on [Semantic Versioning Rules](https://docs.npmjs.com/about-semantic-versioning). It also provides centralized configuration for tools, such as testing.

A `package.json` file **MUST** include the following fields:
  - The `name` field contains our package's name, which must be lowercase and may contain hyphens and underscores (i.e., `my-expresspackage`). Try to choose a name that is unique, descriptive, and meets [`npm` policy guidelines](https://docs.npmjs.com/policies/). Make sure it isn't spelled in a similar way to another package name and that it won't confuse others about authorship.
  - The `version` field must be in the `x.x.x` format and follow semantic versioning guidelines.

### What is Semantic Versioning?

In the `npm` ecosystem, developers follow `npm`'s semantic versioning guidelines when updating their packages' version numbers. Every time we make significant updates to an `npm` package, it's a best practice to publish a new version of the package with an updated version number in the `package.json` file for a few reasons:
  - When we have a consistent system for upticking project dependencies, it helps other developers understand the scoipe of changes in a given version and update their codebases as needed.
  - When we specify and explicit version of a library, it also helps to keep everyone on the same exact version of a package. That way, the whole team runs the same version until the `package.json` file is updated.

**Semver** (semantic versioning) relies on the `x.x.x` three digit format. The first, second, and third digits represent the major release, the minor release, and the patch release, respectively.

Updated packages might contain only backward-compatible bug fixes, such as a patch release or backward-compatible new features, like a minor release. In that case, the package could be incorporated presumable without much hassle.

Changes that break backward compatibility, on the other hand, would typically require a higher level of engineering planning and time to incorporate into the project.

Thanks to semver, we can easily specify any version of a package or require a version higher or lower than what we need. We do this by using special symbols, `~` and `^`, in our `package.json` file's dependency list.

We can use [`npm`'s semver calculater](https://semver.npmjs.com/) to define appropriate and acceptable package ranges for our project dependencies.

What do the `^` (caret/hat symbol) and the `~` (tilde symbol) notations mean when defining package versions here?

```json
"dependencies": {
    "awesome_dep": "^0.13.0",
    "another_awesome_dep": "~5.2.0"
},
```

In our `package.json`, we'll see the following:
   - If we write `~0.13.0`, patch releases will be updated when running `npm install`, meaning `0.13.1` is acceptable but `0.14.0` is not.
   - If we write `^0.13.0`, minor releases will be updated when running `npm install`. So, `0.13.1`, `0.14.0`, and so on are acceptable.
   - If we write `0.13.0`, that exact version will always be used. In other words, the dependency is locked.
