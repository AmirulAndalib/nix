# Public headers directory

include_dirs = [
  include_directories('../..'),
]

config_pub_h = configure_file(
  configuration : configdata_pub,
  output : 'config.hh',
)

headers = [config_pub_h] + files(
  'binary-cache-store.hh',
  'build-result.hh',
  'build/derivation-goal.hh',
  'build/derivation-building-goal.hh',
  'build/derivation-building-misc.hh',
  'build/derivation-trampoline-goal.hh',
  'build/drv-output-substitution-goal.hh',
  'build/goal.hh',
  'build/substitution-goal.hh',
  'build/worker.hh',
  'builtins.hh',
  'builtins/buildenv.hh',
  'common-protocol-impl.hh',
  'common-protocol.hh',
  'common-ssh-store-config.hh',
  'content-address.hh',
  'daemon.hh',
  'derivations.hh',
  'derivation-options.hh',
  'derived-path-map.hh',
  'derived-path.hh',
  'downstream-placeholder.hh',
  'filetransfer.hh',
  'gc-store.hh',
  'globals.hh',
  'http-binary-cache-store.hh',
  'indirect-root-store.hh',
  'keys.hh',
  'legacy-ssh-store.hh',
  'length-prefixed-protocol-helper.hh',
  'local-binary-cache-store.hh',
  'local-fs-store.hh',
  'local-overlay-store.hh',
  'local-store.hh',
  'log-store.hh',
  'machines.hh',
  'make-content-addressed.hh',
  'names.hh',
  'nar-accessor.hh',
  'nar-info-disk-cache.hh',
  'nar-info.hh',
  'outputs-spec.hh',
  'parsed-derivations.hh',
  'path-info.hh',
  'path-references.hh',
  'path-regex.hh',
  'path-with-outputs.hh',
  'path.hh',
  'pathlocks.hh',
  'posix-fs-canonicalise.hh',
  'profiles.hh',
  'realisation.hh',
  'remote-fs-accessor.hh',
  'remote-store-connection.hh',
  'remote-store.hh',
  'restricted-store.hh',
  's3-binary-cache-store.hh',
  's3.hh',
  'serve-protocol-connection.hh',
  'serve-protocol-impl.hh',
  'serve-protocol.hh',
  'sqlite.hh',
  'ssh-store.hh',
  'ssh.hh',
  'store-api.hh',
  'store-cast.hh',
  'store-dir-config.hh',
  'store-open.hh',
  'store-reference.hh',
  'store-registration.hh',
  'uds-remote-store.hh',
  'worker-protocol-connection.hh',
  'worker-protocol-impl.hh',
  'worker-protocol.hh',
)
