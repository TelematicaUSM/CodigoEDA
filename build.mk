%: %.c
	gcc $< -o $@

$(executable): $(source)
