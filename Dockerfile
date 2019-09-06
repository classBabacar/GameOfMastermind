# All of the install instructions are using alpine linux syntax
FROM alpine:edge 

# Making connect 4 directory
RUN mkdir /mastermind

# GCC Dependency 
RUN apk add build-base

# Copying everything into Connect Four folder
COPY ./ mastermind

# Setting working directory
WORKDIR /mastermind


