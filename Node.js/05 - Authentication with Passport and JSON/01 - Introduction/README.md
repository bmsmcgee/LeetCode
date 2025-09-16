# Introduction to Passport.js and JSON Web Tokens

## Passport.js Overview

Passport.js is an easy-to-integrate middleware used for authentication.

Passport.js offers various authentication mechanisms (known as strategies) as individually-packaged modules. Currently, more than 500 authentication strategies exist in the Passport.js ecosystem. Strategies include verifying a username and password, delegated authentication using OAuth, and federated authentication using OpenID.

## JSON Web Tokens Overview

In REST architectures, client-server interactions are typically stateless. A statless server doesn't store any history or state about the client session. After all, server-based sessions are often costly to implement and don't scale well.

Instead, the session state is often stored on the client, such as in the browser's cookie, so the client is responsible for transferring all the information needed to execute a request to the server.

**JSON Web Token (JWT)** is a lightweight and secure approach to transfer the state from the client to the server in a REST framework. JWT is an open-standard authentication strategy that relies on exchanging encoded and cryptographically signed JSON strings between client and server.

JWTs allow us to delegate authentication logic to an authorization server. We can delegate login and signup of a cluster of applications to a single authorization server.

To understand how JWT works, consider a typical login flow that uses JWT-based authentication:

<img width="475" height="343" alt="image" src="https://github.com/user-attachments/assets/28917d8c-357f-4320-b3c4-f970ed68da79" />

1. The client makes an HTTP request to the authorization server, sending along the user's login credentials (email and password).
2. The authorization server validates the user's credentials. If authentication is successful, the server sends a JSON response to the client, including a JWT access token.
3. The client receives the JWT and stores it in the browser (in a cookie).
4. The next time the client makes an HTTP request to a route that requires authentication, it will first attach the JWT to the request's authorization headers before sending the request to the application server hosting the protected API.
5. On receiving the request, the application server extracts the JWT from the request and verifies the embedded signature. If the verification is successful, the server fulfills the request. Otherwise, the request is blocked, and the user will receive an error denying their request to access the resource on the application server.

As we can see, the application server doesn't have to keep access tokens in memoru in between requests so that is can be stateless.

JWTs function like temporary user credentials, so the user doesn't have to provide their password to repeatedly access resources on a server.

## Integrate Passport.js and JWTs into the Express Recipes API

Let's authenticate our users using JWT before allowing them access to provileged routes in the Express Recipes API. We'll need to implement routes to handle user signup and login to support user authentication.

As part of the sign-up process, the user will typically provide a password that they can use to log in to the application going forward. Asd a best practice, the user's password will need to be encrypted before storing it in the database. We can use the [`bcrypt`](https://www.npmjs.com/package/bcrypt) library to do that.

Then, during the login process, the server will need to validate the user's credentials and generate and validate JWTs accordingly. We can use the popular [`json-web-token`](https://www.npmjs.com/package/jsonwebtoken) library to do that.

The [`passport`](https://www.passportjs.org/) and [`passport-jwt`](https://www.passportjs.org/packages/passport-jwt/) libraries allow us to implement a Passport.js authentication strategy based on JWTs.

For simplicity, we'll implement the JWT authentication mechanism directly in the Express Recipes application server rather than in a separate authorization server.
