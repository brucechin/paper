ENCLAVE              = Enclave
SUBDIRS              = $(ENCLAVE)

CC                   = gcc
AS                   = gcc
LD                   = gcc

CFLAGS              += -fPIC -fno-stack-protector -fno-builtin -fno-jump-tables \
                       -fno-common -Wno-attributes -g -D_GNU_SOURCE -O0
INCLUDE              = -I$(SGX_SDK)/include/  -I../common/
LDFLAGS             += -lencl_proxy -lsgx_urts \
                       -lsgx_uae_service -pthread $(SUBDIRS:%=-L %) -L$(SGX_SDK)/lib64/

SOURCES              = $(shell ls *.c ../common/*.c)
OBJECTS              = $(SOURCES:.c=.o)
OUTPUT               = fnr

BUILDDIRS            = $(SUBDIRS:%=build-%)
CLEANDIRS            = $(SUBDIRS:%=clean-%)


.SILENT:
all: $(OUTPUT)
	
run: clean all
	./$(OUTPUT)

$(OUTPUT): $(BUILDDIRS) $(OBJECTS)
	echo "$(INDENT)[LD]" $(OBJECTS) $(LIBS) -o $(OUTPUT) 
	$(LD) $(OBJECTS) $(LDFLAGS) -o $(OUTPUT) 

%.o : %.c
	echo "$(INDENT)[CC] " $<
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

%.o : %.S
	echo "$(INDENT)[AS] " $<
	$(AS) $(INCLUDE) -c $< -o $@

clean: $(CLEANDIRS)
	echo "$(INDENT)[RM]" $(OBJECTS) $(OUTPUT)
	rm -f $(OBJECTS) $(OUTPUT)

$(BUILDDIRS):
	echo "$(INDENT)[===] $(@:build-%=%) [===]"
	$(MAKE) -C $(@:build-%=%) INDENT+="$(INDENT_STEP)" curr-dir=$(curr-dir)/$(@:build-%=%)

$(CLEANDIRS):
	echo "$(INDENT)[===] $(@:clean-%=%) [===]"
	$(MAKE) clean -C $(@:clean-%=%) INDENT+="$(INDENT_STEP)" curr-dir=$(curr-dir)/$(@:build-%=%)
