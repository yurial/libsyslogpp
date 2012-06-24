EAPI=2

KEYWORDS="x86 x86_64"
which git &>/dev/null
if [ $? == 0 ]; then
    inherit git

DESCRIPTION="syslog C++ wrapper"
HOMEPAGE="http://github.com/yurial/syslogpp"

    src_unpack() {
        git_src_unpack
    }

    EGIT_REPO_URI="git://github.com/yurial/libsyslogpp.git"
    if [ "$PV" == "9999" ]; then
        KEYWORDS="~alpha ~amd64 ~arm ~hppa ~ia64 ~mips ~ppc ~s390 ~sh ~sparc ~x86 ~sparc-fbsd ~x86-fbsd"
        EGIT_BRANCH="master"
    else
        EGIT_BRANCH="$P"
    fi
else
    SRC_URI="http://github.com/yurial/libsyslogpp/tarball/$P"
fi

LICENSE="GPL-3"
SLOT="0"
IUSE="debug +pthread"
DEPEND=""
S=${WORKDIR}

src_configure() {
	econf $(use_enable debug) $(use_enable pthread)
}

src_compile() {
	make
}

src_install() {
	make install
}

