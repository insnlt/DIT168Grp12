## HOW TO CONTRIBUTE TO THIS PROJECT

To contribute to this projet, find an issue describing a bug or a faulty feature from the project repository on Github. To be able to contribute, create a new branch for your work. The branch name should follow a pattern, the feature name will include dashes to seperate words (eg. `car-detection`) while bug fixes should be created in seperate branches, appended by -fix (eg. `car-detection-fix`).

While contributing , commit frequently and include a descriptive message each time. After you have fixed the problem, create a pull request. In order for your contribution to be merged with the master branch, the code should be reviewed by atleast one of the assigned member.

## HOW TO PACKAGE AND RELEASE BINARIES OF THIS SOFTWARE

### Package:
We are using Docker for distributing and releasing binaries for the software. To build the project locally you must run this command:

`$ docker build -t dit168grp12.dit -f Dockerfile .`

### Saving as .tar and loading

`$ sudo docker save dit > dit168grp12.dit.tar`
`$ cat dit168grp12.dit.tar | docker load`


### Pulling:
To run docker image you should run the following command:

`$ sudo docker pull insnlt/dit168grp12`

## Demo:
`$ sudo docker run --rm -ti --net=host insnlt/dit168grp12 /opt/dit.Sender`
`$ sudo docker run --rm -ti --net=host insnlt/dit168grp12 /opt/dit.Receiver`

