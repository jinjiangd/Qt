# 用于安装qt相关的库文件
# 由于exe没有依赖到xml, 所以需要单独安装

win32{
qt_install_dir = $$PWD/etc
qt_install.path = $$DESTDIR
qt_install.commands = windeployqt --verbose 3 -compiler-runtime "$$DESTDIR/$$TARGET".exe
INSTALLS *= qt_install
}
