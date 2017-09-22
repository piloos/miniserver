MINISERVER_LICENSE = Barco
MINISERVER_VERSION = HEAD
MINISERVER_SITE = /home/lodco/analyser/miniserver
MINISERVER_SITE_METHOD = local
MINISERVER_INSTALL_STAGING = YES
MINISERVER_INSTALL_TARGET = NO
MINISERVER_DEPENDENCIES += qt5base

define MINISERVER_BUILD_CMDS
  ( pushd $(@D) > /dev/null && \
  $(HOST_DIR)/usr/bin/qmake "BUILDROOT=yes" && \
  $(MAKE)  && \
  popd > /dev/null )
endef

$(eval $(generic-package))
