FROM maven:3.8.4-jdk-11-slim AS builder
COPY . /app
WORKDIR /app
RUN mvn dependency:resolve
RUN mvn package

FROM openjdk:11-jre-slim
COPY --from=builder /app/target/ /app/target/
WORKDIR /app/target/
CMD [ "java", "-jar", "worker-jar-with-dependencies.jar" ]
