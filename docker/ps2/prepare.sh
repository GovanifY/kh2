#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
IMAGE="${KH2_PS2_IMAGE:-kh2-local/ps2-compiler:3.2-ee-040921-objdiff}"
MODE="${1:-ensure}"

if ! command -v docker >/dev/null 2>&1; then
  echo "error: docker is required" >&2
  exit 1
fi

if [[ ! -f "${SCRIPT_DIR}/ee-gcc3.2-040921-full.tar.gz" ]]; then
  echo "error: missing ${SCRIPT_DIR}/ee-gcc3.2-040921-full.tar.gz. Have you ran 'git lfs pull'?" >&2
  exit 1
fi

case "${MODE}" in
  ensure)
    if docker image inspect "${IMAGE}" >/dev/null 2>&1; then
      IMAGE_PLATFORM="$(docker image inspect "${IMAGE}" --format '{{.Os}}/{{.Architecture}}')"
      if [[ "${IMAGE_PLATFORM}" == "linux/amd64" ]]; then
        exit 0
      fi
    fi
    docker build --platform linux/amd64 -t "${IMAGE}" -f "${SCRIPT_DIR}/Dockerfile" "${SCRIPT_DIR}/../.."
    ;;
  --build|build)
    docker build --platform linux/amd64 -t "${IMAGE}" -f "${SCRIPT_DIR}/Dockerfile" "${SCRIPT_DIR}/../.."
    ;;
  *)
    exit 2
    ;;
esac
