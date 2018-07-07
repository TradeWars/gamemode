# -
# TradeWars/gamemode makefile
#
# This is mainly for running Docker tasks and database setup scripts.
# -

VERSION := $(shell cat VERSION)
NEW_VERSION := $(shell date -u +%yw%W.%w.%H)
-include .env


# -
# Local
# -

local:
	sampctl package run --forceBuild 

next:
	echo $(NEW_VERSION) > VERSION


# -
# Docker
# -

build:
	docker build \
		--no-cache \
		--tag southclaws/tw-gamemode:$(VERSION) \
		.

push:
	docker push \
		southclaws/tw-gamemode:$(VERSION)

run:
	docker run \
		southclaws/tw-gamemode:$(VERSION)
