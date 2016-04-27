program_folders = ejemplo_archivos_tutoria3 lista lista_doble


.PHONY: build
build:
	for FOLDER in $(program_folders); \
	do \
	    $(MAKE) -C $$FOLDER; \
	done

.PHONY: $(program_folders)
$(program_folders):
	$(MAKE) -C $@ execute

.PHONY: exec_all
exec_all: $(program_folders)

.PHONY: indent
indent:
	for FOLDER in $(program_folders); \
	do \
	    $(MAKE) -C $$FOLDER indent; \
	done

.PHONY: clean
clean:
	for FOLDER in $(program_folders); \
	do \
	    $(MAKE) -C $$FOLDER clean; \
	done
