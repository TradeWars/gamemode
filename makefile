# -
# samp-sandbox makefile
#
# This is mainly for running Docker tasks and database setup scripts.
# -

VERSION := $(shell cat VERSION)
NEW_VERSION := $(shell date -u +%yw%W.%w.%H)
-include .env


build:
	docker build \
		--no-cache \
		--tag southclaws/samp-sandbox:$(VERSION) \
		.

run:
	docker run \
		southclaws/samp-sandbox:$(VERSION) \

release:
	echo $(NEW_VERSION) > VERSION
