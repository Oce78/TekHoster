FROM node:12-alpine
COPY . /app
WORKDIR /app
RUN npm install
EXPOSE 80
CMD [ "node", "server.js", "--port=80" ]
