FROM hello-world-nds-dependencies

RUN mkdir -p /project /build

COPY . /project

WORKDIR /project

RUN make

COPY /project/project.nds /bin

ENTRYPOINT ["dumb-init", "--"]

CMD ["/bin/bash"]