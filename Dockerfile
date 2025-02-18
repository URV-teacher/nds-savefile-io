FROM aleixmt/bmde-linux:latest

COPY . /workspace/

WORKDIR /workspace/hello-world-nds

RUN make clean && make && make run

CMD ["cp", "hello-world-nds.nds", "/output/"]
