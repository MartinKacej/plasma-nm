add_definitions(-DTRANSLATION_DOMAIN=\"plasmanetworkmanagement_fortisslvpnui\")

set(fortisslvpn_SRCS
    fortisslvpn.cpp
    fortisslvpnwidget.cpp
    fortisslvpnauth.cpp
)

ki18n_wrap_ui(fortisslvpn_SRCS fortisslvpn.ui fortisslvpnadvanced.ui fortisslvpnauth.ui)

add_library(plasmanetworkmanagement_fortisslvpnui ${fortisslvpn_SRCS})

kcoreaddons_desktop_to_json(plasmanetworkmanagement_fortisslvpnui plasmanetworkmanagement_fortisslvpnui.desktop)

target_link_libraries(plasmanetworkmanagement_fortisslvpnui
    plasmanm_internal
    plasmanm_editor
    KF5::I18n
    KF5::WidgetsAddons
    KF5::KIOWidgets
    KF5::CoreAddons
)

install(TARGETS plasmanetworkmanagement_fortisslvpnui  DESTINATION ${KDE_INSTALL_PLUGINDIR})

install(FILES plasmanetworkmanagement_fortisslvpnui.desktop  DESTINATION ${KDE_INSTALL_KSERVICES5DIR})
