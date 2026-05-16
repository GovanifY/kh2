FROM ubuntu:24.04

ARG TOOLCHAIN_ARCHIVE=docker/ps2/ee-gcc3.2-040921-full.tar.gz
ARG TOOLCHAIN_DIR=/opt/ps2/gcc
ARG OBJDIFF_VERSION=3.7.0
WORKDIR /tmp

RUN set -eux; \
    dpkg --add-architecture i386; \
    apt-get update; \
    apt-get install -y --no-install-recommends libc6:i386 libstdc++5:i386 patchelf make python3 wget ca-certificates; \
    wget -qO /usr/local/bin/objdiff-cli "https://github.com/encounter/objdiff/releases/download/v${OBJDIFF_VERSION}/objdiff-cli-linux-x86_64"; \
    chmod +x /usr/local/bin/objdiff-cli; \
    rm -rf /var/lib/apt/lists/*

COPY ${TOOLCHAIN_ARCHIVE} /tmp/toolchain.tar.gz

RUN set -eux; \
    mkdir -p /opt/ps2; \
    tar -xzf /tmp/toolchain.tar.gz -C /opt/ps2; \
    for b in /opt/ps2/gcc/bin/* /opt/ps2/gcc/ee/bin/* /opt/ps2/gcc/lib/gcc-lib/ee/3.2-ee-040921/*; do \
      [ -f "$b" ] || continue; \
      interp="$(patchelf --print-interpreter "$b" 2>/dev/null || true)"; \
      if [ -n "$interp" ] && [ "$interp" != "/lib/ld-linux.so.2" ]; then \
        patchelf --set-interpreter /lib/ld-linux.so.2 "$b"; \
      fi; \
    done; \
    test -x "${TOOLCHAIN_DIR}/bin/ee-g++"; \
    test -x "${TOOLCHAIN_DIR}/bin/ee-as"; \
    test -x "${TOOLCHAIN_DIR}/bin/ee-ld"; \
    test -x "${TOOLCHAIN_DIR}/bin/ee-objdump"; \
    ln -sf "${TOOLCHAIN_DIR}/bin/ee-as" /usr/local/bin/as; \
    ln -sf "${TOOLCHAIN_DIR}/bin/ee-ld" /usr/local/bin/ld; \
    rm -f /tmp/toolchain.tar.gz

ENV PS2_TOOLCHAIN=/opt/ps2/gcc
ENV PATH=${PS2_TOOLCHAIN}/bin:${PATH}

WORKDIR /work
