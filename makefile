# -
# samp-sandbox makefile
#
# This is mainly for running Docker tasks and database setup scripts.
# -

VERSION := $(shell date +%yw%W.%w.%H)
-include .env


build:
	docker build \
		--no-cache \
		--tag southclaws/samp-sandbox:$(VERSION) \
		.

run:
	docker run \
		southclaws/samp-sandbox:$(VERSION) \
