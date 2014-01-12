# -*- Mode: makefile-gmake; tab-width: 4; indent-tabs-mode: t -*-
#
# This file is part of the LibreOffice project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

$(eval $(call gb_Library_Library,iculess))

$(eval $(call gb_Library_use_externals,iculess,\
	icu_headers \
))

$(eval $(call gb_Library_add_defs,vcl,\
    -DICULESS_DLLIMPLEMENTATION \
))

ifneq (,$(filter IOS MACOSX,$(OS)))

$(eval $(call gb_Library_use_system_darwin_frameworks,iculess,\
    CoreFoundation \
))

$(eval $(call gb_Library_add_objcxxobjects,iculess,\
	iculess/source/apple \
))

endif

# vim: set noet sw=4 ts=4:
