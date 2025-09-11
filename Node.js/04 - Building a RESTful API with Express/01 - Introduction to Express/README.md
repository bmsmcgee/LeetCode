# Introduction to Express

## Express Overview

Node.js is commonly used as a web server to serve up websites, JSON, and more. [Express](https://expressjs.com/) is a popular server-side framework for building web applications on Node.js.

Express provides a lightweight abstraction over the Node.js HTTP modules and convenience methods for creating routing, views, and middleware.

We'll build a RESTful API that allows API consumers to retrieve, create, update, and delete a set of recipes. 

## The Node Package Manager and Node Community

The [Node Package Manager](https://www.npmjs.com/) (npm) consists of three distinct components:
  1. The npm is the world's largest JavaScript software registry. Open-source developers from across the globe use npm to share and borrow packages, and many organizations use `npm` to manage private development as well. The extensive public database of packages means there's a package for almost everything! We can download and adapt these packages for our applications or incorporate them as they are. However, since anybody can publish a package to the `npm` registry, `npm` packages might not all be of the same quality. Often, there are dozens or even hundreds of packages with similar names and purposes, so it's essential to select the most appropriate package for our project.
  2. The The `npm` also provides a user interface for managing our public and private packages and other aspects of our `npm` experience, like creating organizations to coordinate package maintenance and restricting code to specific developers.
  3. The `npm` also refers to the command-line interface (CLI) tool for downloading and managing Node.js packages. It comes bundled with our Node.js installation and is how most developers interact with the `npm` registry. While `npm` is the standard package manager for Node.js, there are other alternatives, such as [Yarn](https://yarnpkg.com/).

### What Criteria Would Apply to Select Packages for a Project?

When we use the search bar on the [`npm` website](https://www.npmjs.com/) to find packages, it returns a list of packages that can be ranked by four criteria:
  1. **Popularity**: How popular is the package? If a package has thousands or even millions of downloads, that's probably a strong indicator that others have found the package to be useful. Check out [`npm` trends](https://npmtrends.com/), where we can compare the popularity of different comparable packages.
  2. **Quality**: What steps have the package creator or maintainer taken to ensure high quality? The presence of a `README` file, package stability, tesdts, and up-to-date dependencies are characteristics of a high-quality package.
  3. **Maintenance**: How well maintained is the package? Is the package frequently updated to work well with other dependencies or new versions of the `npm` CLI?
  4. **Optimality**: How optimal is the package? Optimal combines the three criteria mentioned above (popularity, quality, and maintenance) into one meangingful score.
