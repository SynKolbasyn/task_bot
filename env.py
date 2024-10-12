try:
  from dotenv import dotenv_values
except ImportError:
  env.Execute("$PYTHONEXE -m pip install python-dotenv")
  from dotenv import dotenv_values


build_flags = [f'-D {key}=\\"{val}\\"' for key, val in dotenv_values(".env").items()]

Import("env")
env.Append(BUILD_FLAGS=build_flags)
