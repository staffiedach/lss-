pkgname=lss
pkgver=1.0
pkgrel=1
pkgdesc='lss is a command line tool that adds on to the deafault ls command.'
arch=('any')
source=('main.cpp')
sha256sums=('SKIP')

build() {
 g++ $CXXFLAGS $LDFLAGS main.cpp -o lss
}

package() {
 install -Dm755 lss "${pkgdir}/usr/bin/lss"
}
