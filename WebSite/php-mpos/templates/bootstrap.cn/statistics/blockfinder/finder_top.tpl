  <div class="col-lg-6">
    <div class="panel panel-info">
      <div class="panel-heading">
        <i class="fa fa-user fa-fw"></i> 前 25 名区块发现者
      </div>
      <div class="panel-body no-padding table-responsive">
        <table class="table table-striped table-bordered table-hover">
          <thead>
            <tr>
              <th>名次</th>
              <th>用户名</th>
              <th>区块</th>
              <th>产生的币</th>
            </tr>
          </thead>
          <tbody>
{assign var=rank value=1}
{section block $BLOCKSSOLVEDBYACCOUNT}
      <tr>
              <td>{$rank++}</td>
              <td>{if $BLOCKSSOLVEDBYACCOUNT[block].is_anonymous|default:"0" == 1 && $GLOBAL.userdata.is_admin|default:"0" == 0}anonymous{else}{$BLOCKSSOLVEDBYACCOUNT[block].finder|default:"unknown"|escape}{/if}</td>
              <td>{$BLOCKSSOLVEDBYACCOUNT[block].solvedblocks}</td>
              <td>{$BLOCKSSOLVEDBYACCOUNT[block].generatedcoins|number_format}</td>
            </tr>
{/section}
          </tbody>
        </table>
      </div>
    </div>
  </div>
