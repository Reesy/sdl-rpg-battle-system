FROM node:stretch-slim

EXPOSE 3000

COPY ./embuild/resources ./embuild/resources

COPY ./embuild/index.html  \
     ./embuild/icon.png \ 
     ./embuild/SDLRPGBATTLESYSTEM.data \
     ./embuild/SDLRPGBATTLESYSTEM.js \
     ./embuild/SDLRPGBATTLESYSTEM.wasm \
     ./embuild

RUN npm install -g serve

CMD ["serve", "-s", "./embuild"]