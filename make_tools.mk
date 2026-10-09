# This controls building executables in the `tools` folder.
# Can be invoked through the `Makefile` or standalone.

MAKEFLAGS += --no-print-directory

# Inclusive list. If you don't want a tool to be built, don't add it here.
TOOLS_DIR := tools
TOOL_NAMES := bin2c gbafix gbagfx jsonproc mapjson mid2agb preproc ramscrgen rsfont scaninc wav2agb poryscript

# Only build tool subdirs that actually contain a Makefile.
# Some tools (like poryscript) are shipped as prebuilt binaries and should not be invoked via `make -C`.
TOOLDIRS := $(TOOL_NAMES:%=$(TOOLS_DIR)/%)
MAKEABLE_TOOLDIRS := $(foreach dir,$(TOOLDIRS),$(if $(wildcard $(dir)/Makefile),$(dir)))

# Tool making doesnt require a pokefirered dependency scan.
RULES_NO_SCAN += tools check-tools clean-tools $(MAKEABLE_TOOLDIRS)
.PHONY: $(RULES_NO_SCAN)

tools: $(MAKEABLE_TOOLDIRS)

$(MAKEABLE_TOOLDIRS):
	@$(MAKE) -C $@

clean-tools:
	@$(foreach tooldir,$(MAKEABLE_TOOLDIRS),$(MAKE) clean -C $(tooldir);)
