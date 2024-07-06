# Variant Error
A type safe way to bubble error up to a main calling code.

## Background
Exceptions are nasty, they are suddenly called, we don't know when they will be called and they are very implicit without any documentation. Using variant_error and std::expected, now it is possible to persist the whole error types up until the point of calling.