# All of the install instructions are using alpine linux syntax
FROM alpine:edge 

# Making mastermind directory
RUN mkdir /mastermind

# GCC Dependency
RUN apk add build-base

# Copying everything into mastermind folder
COPY ./ mastermind

# Setting working directory
WORKDIR /mastermind


