In order to build the game, you need to have previously installed the CSFML package,
if you don't want to dedicate precious memory space to this, you can use the Dockerfile included !

to do so :

#Build an image from the Dockerfile included
docker image build -t ${name} .

#Compile the project thanks to a container generated from the newly created container
docker run --mount type=bind,source="$(pwd)",destination=/My-Hunter-Epitech ${name} make

#Start the game
docker run --mount type=bind,source="$(pwd)",destination=/My-Hunter-Epitech -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -h $HOSTNAME ${name} ./my_hunter
