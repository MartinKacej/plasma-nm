/*
    Copyright 2013-2014 Jan Grulich <jgrulich@redhat.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

import QtQuick 2.2
import org.kde.plasma.components 2.0 as PlasmaComponents
import org.kde.plasma.core 2.0 as PlasmaCore

PlasmaComponents.ListItem {
    id: header;

    property alias text: headerLabel.text;

    anchors {
        left: parent.left;
        right: parent.right;
    }

    height: headerLabel.height + units.gridUnit;
    sectionDelegate: true;

    PlasmaComponents.Label {
        id: headerLabel;

        anchors {
            horizontalCenter: parent.horizontalCenter;
            verticalCenter: parent.verticalCenter;
        }

        height: paintedHeight;
        font.weight: Font.DemiBold;
    }

    PlasmaCore.FrameSvgItem {
        id: buttonFrame;

        anchors {
            fill: refreshButton;
            bottomMargin: -Math.round(units.gridUnit / 3);
            leftMargin: -Math.round(units.gridUnit / 3);
            rightMargin: -Math.round(units.gridUnit / 3);
            topMargin: -Math.round(units.gridUnit / 3);
        }

        width: height;
        imagePath: "widgets/button"
        prefix: "normal"
        visible: header.text == i18n("Available connections") && refreshButtonMouseArea.containsMouse;
    }

    PlasmaCore.SvgItem {
        id: refreshButton;

        anchors {
            bottom: parent.bottom;
            right: parent.right;
            rightMargin: Math.round(units.gridUnit / 2);
            top: parent.top;
        }

        width: height;
        elementId: "view-refresh"
        visible: header.text == i18n("Available connections");
        svg: PlasmaCore.FrameSvg { imagePath: "icons/view" }

        RotationAnimation {
            id: animation;

            direction: RotationAnimation.Clockwise
            duration: 1000;
            from: 0;
            to: 720;
            target: refreshButton;
            // Workaround for warning message about non-existing property "rotation"
            // BUG: https://bugreports.qt-project.org/browse/QTBUG-22141
            property: "rotation";
        }

        MouseArea {
            id: refreshButtonMouseArea;

            anchors.fill: parent;
            hoverEnabled: true;

            onClicked: {
                handler.requestScan();
                animation.start();
            }
        }
    }
}