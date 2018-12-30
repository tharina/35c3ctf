# 35C3 Junior CTF pwnables

Source code and exploits for the 35C3 Junior CTF pwnables.

To recreate the CTF environment with docker enter the challenge directory and run:

```
./docker_build.sh
./docker_run.sh
```

For each challenge the files in the respective subdirectory `distrib` were given.

Note: For some exploits offsets to libc symbols are used. These can change when the libc used in the docker container is updated. Use the following command to retrieve the libc currently used in the docker environment:
```
docker cp -L <challenge_name>:/lib/x86_64-linux-gnu/libc.so.6 .
```


## poet

We are looking for the poet of the year:

`nc localhost 22223`

Difficulty estimate: very easy


## 1996

It's 1996 all over again!

`nc localhost 22227`

Difficulty estimate: very easy


## stringmaster1

Eat, sleep, swap, replace

`nc localhost 22224`

Difficulty estimate: easy


## stringmaster2

Eat, sleep, swap, replace

This time with more mitigations!

`nc localhost 22225`

Difficulty estimate: medium

## sum

Sum it up!

`nc localhost 22226`

Difficulty estimate: easy


## arraymaster1

Would you mind briefly testing our new integer array implementation?

`nc localhost 22228`

Difficulty estimate: easy - medium


## arraymaster2

We improved our security with more mitigations.

`nc localhost 22229`

Difficulty estimate: hard
